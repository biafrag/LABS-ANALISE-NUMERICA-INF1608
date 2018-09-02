#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "sistlinear.h"
void printar(int n,double** A)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%lf ",A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void printavet(int n,int *v)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",v[i]);
	}
	printf("\n");
	return;
}
void printavetdouble(int n, double *v)
{
	int i;
	for (i = 0; i<n; i++)
	{
		printf("%lf ", v[i]);
	}
	printf("\n");
	return;
}
int* fatoracao (int n, double** A)
{
	int i,j,k,auxV;
	double f, auxM;
	int *v,p;
	v=(int*)malloc(sizeof(int*)*n);
	//inicializando vetor de permutação
	for(i=0;i<n;i++)
	{
		v[i]=i;
	}
	for(j=0;j<n-1;j++)
	{
		p=j;
		for(k=j+1;k<n;k++)
		{
			if(fabs(A[k][j])>fabs(A[p][j]))
			{
				p=k;
			}
		}
		if (j != p)
		{
			//troca as linhas
			for (k = 0; k < n; k++)
			{
				auxM = A[j][k];
				A[j][k] = A[p][k];
				A[p][k] = auxM;
			}
			auxV = v[j];
			v[j] = v[p];
			v[p] = auxV;
		}
		for(i=j+1;i<n;i++)
		{
			f=A[i][j]/A[j][j];
			for(k=j+1;k<n;k++)
			{
				A[i][k]=A[i][k]-(f*A[j][k]);
			}
			//Colocando em A valores de 
			A[i][j] = f;
		}
	}
	return v;
}
double* substituicao (int n, double** A, int* p, double* b)
{
	double *x,*y;
	double s;
	int i, j;
	x = (double*)malloc(sizeof(double)*n);
	y = (double*)malloc(sizeof(double)*n);
	for (i = 0; i < n; i++)
	{
		s = 0;
		for (j = 0; j<i; j++)
		{
			s += A[i][j] * y[j];
		}
		y[i] = (b[p[i]] - s);
	}
	for (i = n-1; i>=0; i--)
	{
		s = 0;
		for (j = i+1; j<n; j++)
		{
			s += A[i][j] * x[j];
		}
		x[i] = (y[i] - s)/A[i][i];
	}
	return x;
}