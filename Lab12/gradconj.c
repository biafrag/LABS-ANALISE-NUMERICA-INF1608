#include <stdio.h>
#include "gradconj.h"
#include <stdlib.h>
#include "vetmat.h"
int GradConj (int n, double** A, double* b, double* x, double tol)
{
	int i,j,k,cont;
	double aux=0;
	double *r;
	double *rk;
	double *d;
	double *Ax;
	double alfa=0;
	double beta;
	double *Aux;
	double **AuxM;
	r=vetcria(n);
	rk=vetcria(n);
	d=vetcria(n);
	Ax=vetcria(n);
	Aux=vetcria(n);
	AuxM=matcria(n,n);
	//Ax0
	multmv (n,n,A, x, Ax);
	//r0=b-Ax0
	//d0=b-Ax0
	for(i=0;i<n;i++)
	{
		r[i]=b[i]-Ax[i];
		d[i]=b[i]-Ax[i];
	}
	cont = 0;
	for(k=0;k<n;k++)
	{
		if (tol > norma2(n, r))
		{
			break;
		}
		//Alfa=rkT*rk
		alfa = escalar(n, r, r);
		//A*dk
		multmv(n, n, A, d, Aux);
		//A*d*d
		aux = escalar(n, d, Aux);
		alfa =alfa/aux;
		for (i = 0; i < n; i++)
		{
			x[i] = x[i] + alfa*d[i];
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				AuxM[i][j] = A[i][j] * alfa;
			}
		}
		multmv(n, n, AuxM, d, Aux);
		for (i = 0; i < n; i++)
		{
			rk[i] = r[i] - Aux[i];
		}
		beta = (escalar(n, rk, rk)) / (escalar(n, r, r));
		for (i = 0; i < n; i++)
		{
			d[i] = rk[i] + beta*d[i];
			r[i] = rk[i];
		}
		cont++;
	}
	return cont;
	

}
double **criaprecondicionador(int n, double ** A)
{
	int i, j;
	double **M1;
	M1 = matcria(n, n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			M1[i][j] = 0;
			if (i == j)
			{
				M1[i][j] = 1 / A[i][j];
			}
		}
	}
	return M1;

}
int GradConjJacobi (int n, double** A, double* b, double* x, double tol)
{
	int i, j, k, cont;
	double aux = 0;
	double *r;
	double *rk;
	double *d,*z,*zk;
	double *Ax;
	double alfa = 0;
	double beta;
	double *Aux;
	double **AuxM;
	double **M1;
	r = vetcria(n);
	rk = vetcria(n);
	d = vetcria(n);
	z = vetcria(n);
	zk = vetcria(n);
	Ax = vetcria(n);
	Aux = vetcria(n);
	M1 = criaprecondicionador(n,A);
	AuxM = matcria(n, n);
	multmv(n, n, A, x, Ax);
	cont = 0;
	for (i = 0; i<n; i++)
	{
		r[i] = b[i] - Ax[i];
	}
	multmv(n, n, M1, r, d);
	multmv(n, n, M1, r, z);

	for (k = 0;k < n;k++)
	{
		if (tol > norma2(n, r))
		{
			break;
		}
		alfa = escalar(n, r, z);
		multmv(n, n, A, d, Aux);
		aux = escalar(n, d, Aux);
		alfa /= aux;
		for (i = 0; i < n; i++)
		{
			x[i] = x[i] + alfa*d[i];
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				AuxM[i][j] = A[i][j] * alfa;
			}
		}
		multmv(n, n, AuxM, d, Aux);
		for (i = 0; i < n; i++)
		{
			rk[i] = r[i] - Aux[i];
		}
		multmv(n, n, M1, rk, zk);
		beta = escalar(n, rk, zk) / escalar(n, r, z);
		for (j = 0; j < n; j++)
		{
			Aux[i] = beta*d[i];
		}
		for (i = 0; i < n; i++)
		{
			d[i] = zk[i] + beta*d[i];;
			r[i] = rk[i];
			z[i] = zk[i];
		}
		cont++;
	}

	return cont;
}