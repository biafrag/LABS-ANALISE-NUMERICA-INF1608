#include <stdio.h>
#include <malloc.h>
#include "vetmat.h"

int main (void)
{
	double *vetor;
	double result;
	double *vetor2;
	double *vetor3;
	double **A1;
	double **A2;
	double **T1;
	double norm;
	double *resultMV;
	double **resultMM;
	double **A3;
	int ehigualV;
	int ehigualV2;
	int ehigualM;
	int ehigualM2;
	//Testando criar
	vetor= vetcria (2);
	vetor[0]=1;
	vetor[1]=2;
	printf("Vetor: %lf %lf\n",vetor[0],vetor[1]);

	//Testando produto escalar
	vetor2= vetcria (2);
	vetor2[0]=2;
	vetor2[1]=3;
	result= escalar(2, vetor, vetor2);
	printf("Resultado esperado calculado na mao: 8\n");
	printf("Resultado da funcao: %lf\n",result);

	//Testando norma de um vetor
	norm=norma2(2,vetor);
	printf("Resultado esperado calculado na mao: 2.23\n");
	printf("Resultado da funcao: %lf\n",norm);

	//Testando se vetores são iguais
	ehigualV= vetiguais (2, vetor, vetor2, 0.0001);
	if(ehigualV)
	{
		printf("Eh igual!!!\n");
	}
	else
	{
		printf("Nao eh igual!!!\n");
	}

	vetor3= vetcria (2);
	vetor3[0]=1;
	vetor3[1]=2;

	ehigualV2= vetiguais (2, vetor, vetor3, 0.0001);

	if(ehigualV2)
	{
		printf("Eh igual!!!\n");
	}
	else
	{
		printf("Nao eh igual!!!\n");
	}

	//Testando impressão
	printf("Vetor:\n");
	vetimprime (2, vetor, "%.3g");
	
	//Criando uma matriz
	A1=matcria (2, 2);
	A1[0][0]=1;
	A1[0][1]=2;
	A1[1][0]=3;
	A1[1][1]=4;
	
	//Imprime matriz
	printf("Matriz:\n");
	matimprime (2, 2,A1,"%f");

	//Testando transposta
	T1=matcria (2, 2);
	transposta (2,2,A1,T1);
	printf("Matriz Transposta:\n");
	matimprime (2, 2,T1,"%f");

	//Testando multiplicação de matriz por vetor
	resultMV = vetcria (2);
	multmv (2, 2,A1,vetor,resultMV);
	printf("Vetor Resultante :\n");
	vetimprime (2, resultMV, "%f");

	//Testando matrizes iguais
	A2=matcria (2, 2);
	A2[0][0]=1;
	A2[0][1]=2;
	A2[1][0]=3;
	A2[1][1]=4;
	ehigualM=matiguais (2,2,A1,A2,0.0001);

	if(ehigualM)
	{
		printf("A matriz eh igual!!!\n");
	}
	else
	{
		printf("A matriz n eh igual!!!\n");
	}

	//Testando multiplicação de matrizes
	A2[0][0]=1;
	A2[0][1]=1;
	A2[1][0]=1;
	A2[1][1]=1;

	ehigualM2=matiguais (2,2,A1,A2,0.0001);

	if(ehigualM2)
	{
		printf("A matriz eh igual!!!\n");
	}
	else
	{
		printf("A matriz n eh igual!!!\n");
	}
	printf("A1:\n");
	matimprime (2, 2,A1,"%f");
	printf("A2:\n");
	matimprime (2, 2,A2,"%f");
	resultMM=matcria(2,2);
	multmm (2, 2, 2,A1,A2, resultMM);
	printf("Resultado da multipicacao de matrizes:\n");
	matimprime (2, 2,resultMM,"%f");
	A3=matcria (2, 3);
	A3[0][0]=1;
	A3[0][1]=1;
	A3[0][2]=1;
	A3[1][0]=3;
	A3[1][1]=2;
	A3[1][2]=1;
	multmm (2, 2, 3,A1,A3, resultMM);
	printf("Resultado da multipicacao de matrizes:\n");
	matimprime (2, 3,resultMM,"%f");

	vetlibera (vetor);
	vetlibera (vetor2);
	matlibera (2,A1);
	matlibera (2,A2);
	matlibera (2,A3);

}