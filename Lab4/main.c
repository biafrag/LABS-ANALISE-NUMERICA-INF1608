#include<stdio.h>
#include "sistlinear.h"
#include <malloc.h>
double* vetcria (int n) //1
{
	double *v;
	v=(double*)malloc(sizeof(double)*n);
	return v;
}
double** matcria (int m, int n) //7
{
	double **M;
	int i;
	M=(double**)malloc(sizeof(double*)*m);
	for(i=0;i<m;i++)
	{
		M[i]=vetcria(n);
	}

	return M;
}
int main(void)
{
	double **A,*bA,**B,*bB,*x;
	int *p;
	bA = vetcria(3);
	A=matcria(3,3);
	A[0][0]=1;
	A[0][1]=2;
	A[0][2]=-1;
	A[1][0]=2;
	A[1][1]=1;
	A[1][2]=-2;
    A[2][0]=-3;
	A[2][1]=1;
	A[2][2]=1;
	bB = vetcria(6);
	B = matcria(6, 6);
	B[0][0] = 3;
	B[0][1] = -1;
	B[0][2] = 0;
	B[0][3] = 0;
	B[0][4] = 0;
	B[0][5] = 0.5;
	B[1][0] = -1;
	B[1][1] = 3;
	B[1][2] = -1;
	B[1][3] = 0;
	B[1][4] = 0.5;
	B[1][5] = 0;
	B[2][0] = 0;
	B[2][1] = -1;
	B[2][2] = 3;
	B[2][3] = -1;
	B[2][4] = 0;
	B[2][5] = 0;
	B[3][0] = 0;
	B[3][1] = 0;
	B[3][2] = -1;
	B[3][3] = 3;
	B[3][4] = -1;
	B[3][5] = 0;
	B[4][0] = 0;
	B[4][1] = 0.5;
	B[4][2] = 0;
	B[4][3] = -1;
	B[4][4] = 3;
	B[4][5] = -1;
	B[5][0] = 0.5;
	B[5][1] = 0;
	B[5][2] = 0;
	B[5][3] = 0;
	B[5][4] = -1;
	B[5][5] = 3;

	bA[0] = 3;
	bA[1] = 3;
	bA[2] = -6;

	bB[0] = 2.5;
	bB[1] = 1.5;
	bB[2] = 1;
	bB[3] = 1;
	bB[4] = 1.5;
	bB[5] = 2.5;
	printf("Matriz A\n\n");
	printf("Como ela eh no inicio\n");
	printar(3,A);
	p=fatoracao(3,A);
	printf("Como ela fica depois da fatoracao:\n");
	printar(3,A);
	printf("Vetor de permutacao:\n");
	printavet(3, p);
	x=substituicao(3, A, p, bA);
	printf("Vetor resultado:\n");
	printavetdouble(3, x);
	printf("\nMatriz B\n");
	printf("Como ela eh no inicio\n");
	printar(6, B);
	p = fatoracao(6, B);
	printf("Como ela fica depois da fatoracao:\n");
	printar(6, B);
	printf("Vetor de permutacao:\n");
	printavet(6, p);
	x=substituicao(6, B, p, bB);
	printf("Vetor resultado:\n");
	printavetdouble(6, x);
	return 0;
}