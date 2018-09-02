#include "mmq.h"
#include <math.h>
double* mmq (int m, int n, double** A, double* b)
{
	double *x,*bt;
	int* p;
	double **At,**Aat;
	At=matcria(m,n);
	Aat=matcria(n,n);
	bt=vetcria(n);
	transposta (m,n,A,At);
	multmv (n,m, At, b, bt);
	x=vetcria(n);
	multmm (n,m,n,At,A,Aat);
	p=fatoracao (n, Aat);
	x=substituicao (n,Aat,p,bt);
	return x;
}
double mmqNorma2 (int m, int n, double** A, double* b, double* x)
{
	int i;
	double *Ax,soma;
	soma=0;
	Ax=vetcria(m);
	multmv(m,n,A,x,Ax);
	for(i=0;i<n;i++)
	{
		soma+=(b[i]-Ax[i])*(b[i]-Ax[i]);
	}
	return sqrt(soma);
}
double concentracao (int n, double* t, double* c, double* pa, double* pb)
{

}