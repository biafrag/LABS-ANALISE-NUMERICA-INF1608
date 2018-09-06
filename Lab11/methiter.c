#include "methiter.h"
#include <malloc.h>
#include <math.h>
int Jacobi (int n, double** A, double* b, double* x, double tol)
{
	int i,j;
	double *y;
	double S=0;
	int cont=0;
	double norma2;
	y=(double*)malloc(n*sizeof(double));
	norma2=10000000000000000000000.0;
	while(norma2>tol)
	{
		for(j=0;j<n;j++)
		{
			y[j]=x[j];	 
		}
		norma2=0;
		for(i=0;i<n;i++)
		{
			S=0;
			for(j=0;j<n;j++)
			{
				if(i!=j)
				{
					S+=A[i][j]*y[j];
				}
			}

			x[i]= (b[i] - S)/A[i][i]; 
			norma2+=(x[i]-y[i])*(x[i]-y[i]);
		}
		norma2=sqrt(norma2);
		cont++;
	}
	free(y);
	return cont;
}
int GaussSeidel (int n, double** A, double* b, double* x, double tol)
{
	int i,j;
	double y;
	double S=0;
	int cont=0;
	double norma2;
	norma2=10000000000000000000000.0;
	while(norma2>tol)
	{

		for(i=0;i<n;i++)
		{
			norma2=0;
			S=0;
			for(j=0;j<n;j++)
			{
				if(i!=j)
				{
					S+=A[i][j]*x[j];
				}
			}
			y=x[i];
			x[i]= (b[i] - S)/A[i][i]; 
			norma2+=(x[i]-y)*(x[i]-y);
		}
		norma2=sqrt(norma2);
		cont++;
	}
	return cont;

}
int SOR (int n, double** A, double* b, double* x, double tol, double w)
{
	int i,j;
	double y;
	double S=0;
	int cont=0;
	double norma2;
	norma2=10000000000000000000000.0;
	while(norma2>tol)
	{

		for(i=0;i<n;i++)
		{
			norma2=0;
			S=0;
			for(j=0;j<n;j++)
			{
				if(i!=j)
				{
					S+=A[i][j]*x[j];
				}
			}
			y=x[i];
			x[i]= (b[i] - S)/A[i][i]; 
			x[i]=(1-w)*y+w*x[i];
			norma2+=(x[i]-y)*(x[i]-y);
		}
		norma2=sqrt(norma2);
		cont++;
	}
	return cont;
}