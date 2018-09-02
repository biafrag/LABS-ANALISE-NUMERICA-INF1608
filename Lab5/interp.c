#include "interp.h"
#include <stdio.h>
#include <malloc.h>
#include<math.h>
#include <assert.h>
#define PI 3.1413
double* Chebyshev (int n, double a, double b)
{
	int i,beta;
	double *x;
	x=(double*)malloc(n*sizeof(double));
	assert(x);
	for(i=0,beta=1;i<n;i++)
	{
		x[i]=((b-a)/2)*cos((beta*PI)/(2*n))+((a+b)/2);
		beta+=2;
	}
	return x;
}
double Aux(int i,int j,double* xi,double**cache)
{
	if(i==j)
	{
		return cache[i][j];
	}
	if(cache[j][i+1]==0)
	{
		cache[j][i+1]++;
		cache[i+1][j] = Aux(i+1,j,xi,cache);
	}
	if(cache[j-1][i]==0)
	{
		cache[j-1][i]++;
		cache[i][j-1]=Aux(i,j-1,xi,cache);
	}
	return (cache[i+1][j]-cache[i][j-1])/ (xi[j] - xi[i]);
}
double* vetcria (int n) //1
{
	double *v;
	v=(double*)malloc(sizeof(double)*n);
	return v;
}
double ** CriaMatriz(double (*f) (double),int n,double* xi)
{
	int i,j;
	double **M;
	M=(double**)malloc(sizeof(double*)*n);
	for(i=0;i<n;i++)
	{
		M[i]=vetcria(n);

	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				M[i][j]=f(xi[i]);
			}
			else
			{
				M[i][j]=0;
			}
		}
	}
	return M;
}
double* NewtonCoef (int n, double* xi, double (*f) (double))
{
	int i,j;
	double*b;
	double **M;
	b=(double*)malloc(n*sizeof(double));
	M=CriaMatriz(f,n,xi);
	for(j=0;j<n;j++)
	{
		b[j]=Aux(0,j,xi,M);
		printf("b[%d]=%lf\n",j,b[j]);
	}
	return b;
}

double NewtonAval (int n, double* xi, double* bi, double x)
{
	int i,j;
	double result=0;
	double calc;
	for(i=0;i<n;i++)
	{
		calc=bi[i];
		for(j=0;j<i;j++)
		{
			calc*=(x-xi[j]);
		}
		result+=calc;
	}
	printf("result:%lf\n",result);
	return result;
}