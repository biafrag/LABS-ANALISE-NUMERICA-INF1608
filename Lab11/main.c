#include "methiter.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
int main (void)
{
	double Aux[2][2] = {{3,1},{1,2}};
	double Aux2[6][6]={{3,-1,0,0,0,0.5},{-1,3,-1,0,0.5,0},{0,-1,3,-1,0,0},{0,0,-1,3,-1,0},{0,0.5,0,-1,3,-1},{0.5,0,0,0,-1,3}};
	double b[2] = {5,5};
	double b2[6]={2.5,1.5,1,1,1.5,2.5};
	double x[2] = {0,0};
	double x2[6]={0,0,0,0,0,0};
	int n = 2;
	int n2 = 6;
	int i,j;
	int count;
	double **A = (double**)malloc(n*sizeof(double*));
	double **A2= (double**)malloc(n2*sizeof(double*));
	if(A==NULL) {
		exit(-1);
	}
	for(i=0;i<n;i++)
	{
		A[i] = (double*)malloc(n*sizeof(double));
		if(A[i]==NULL) {
			exit(-1);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			A[i][j] = Aux[i][j];
		}
	}
	if(A2==NULL) {
		exit(-1);
	}
	for(i=0;i<n2;i++)
	{
		A2[i] = (double*)malloc(n2*sizeof(double));
		if(A2[i]==NULL) {
			exit(-1);
		}
	}
	for(i=0;i<n2;i++)
	{
		for(j=0;j<n2;j++)
		{
			A2[i][j] = Aux2[i][j];
		}
	}
	printf("PRIMEIRO SISTEMA\n\n");
	printf("Jacobi\n\n");
	count=Jacobi(n,A,b,x,pow(10.0,-7));
	for(i=0;i<n;i++)
	{
		printf("x[%d]:%.11g\n\n",i,x[i]);
	}
	
	printf("Numero de iteracoes: %d\n\n",count);
	for(j=0;j<n;j++)
    {
		x[j]=0;
	}
	printf("Gauss Seidel\n\n");
	count=GaussSeidel(n, A, b, x, pow(10.0,-7));
	for(i=0;i<n;i++)
	{
		printf("x[%d]:%.11g\n\n",i,x[i]);
	}
	printf("Numero de iteracoes: %d\n\n",count);

	for(j=0;j<n;j++)
	{
		x[j]=0;
	}
	printf("Gauss Seidel sobre-relaxamento (w=1.2)\n\n");
	count=SOR (n,A,b,x,pow(10.0,-7),1.2);
	for(i=0;i<n;i++)
	{
		printf("x[%d]:%.11g\n\n",i,x[i]);
	}
	printf("Numero de iteracoes: %d\n\n",count);

	printf("SEGUNDO SISTEMA\n\n");
	printf("Jacobi\n\n");
	count=Jacobi(n2,A2,b2,x2,pow(10.0,-7));
	for(i=0;i<n2;i++)
	{
		printf("x[%d]:%.11g\n\n",i,x2[i]);
	}
	
	printf("Numero de iteracoes: %d\n\n",count);
	for(j=0;j<n2;j++)
    {
		x2[j]=0;
	}
	printf("Gauss Seidel\n\n");
	count=GaussSeidel(n2, A2, b2, x2, pow(10.0,-7));
	for(i=0;i<n2;i++)
	{
		printf("x[%d]:%.11g\n\n",i,x2[i]);
	}
	printf("Numero de iteracoes: %d\n\n",count);

	for(j=0;j<n2;j++)
	{
		x2[j]=0;
	}
	printf("Gauss Seidel sobre-relaxamento (w=1.2)\n\n");
	count=SOR (n2,A2,b2,x2,pow(10.0,-7),1.2);
	for(i=0;i<n2;i++)
	{
		printf("x[%d]:%.11g\n\n",i,x2[i]);
	}
	printf("Numero de iteracoes: %d\n\n",count);
	return 0;
}