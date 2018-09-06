#include "gradconj.h"
#include "vetmat.h"
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
		if(A2[i]==NULL)
		{
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
	printf("\n\nPRIMEIRA MATRIZ SEM CONDICIONADOR\n\n");
	count= GradConj (n,A, b, x,0.0001);
	printf("Vezes:%d\n", count);
	vetimprime(n, x, "%f");
	for (j = 0; j<n; j++)
	{
		x[j] = 0;
	}
	printf("\n\nPRIMEIRA MATRIZ COM CONDICIONADOR\n\n");
	count = GradConjJacobi(n, A, b, x, 0.0001);
	printf("Vezes:%d\n",count);
	vetimprime(n,x,"%f");
	
	printf("\n\nSEGUNDA MATRIZ SEM CONDICIONADOR\n\n");
	count = GradConj(n2, A2, b2, x2, 0.0001);
	printf("Vezes:%d\n", count);
	vetimprime(n2, x2, "%f");
	for (j = 0; j<n2; j++)
	{
		x2[j] = 0;
	}
	printf("\n\nSEGUNDA MATRIZ COM CONDICIONADOR\n\n");
	count = GradConjJacobi(n2, A2, b2, x2, 0.0001);
	printf("Vezes:%d\n", count);
	vetimprime(n2, x2, "%f");
}