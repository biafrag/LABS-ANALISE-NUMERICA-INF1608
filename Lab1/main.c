#include "taylor.h"
#include <stdio.h>
#include <math.h>
#define VALOR1 1.2
#define VALOR2 0.1

int main (void)
{
	double teste1,erroMax1,teste2,erroMax2,aux;
	teste1=fsqrt(VALOR1);
	printf("Valor calculado pelo computador:%.9g\n",sqrt(VALOR1));
	printf("Valor encontrado: %lf\n",teste1);
	printf("Diferenca entre um e outro: %lf\n",fabs(teste1-sqrt(VALOR1)));
	erroMax1= fsqrt_erro (VALOR1);
	printf("Erro maximo possivel:%lf\n",erroMax1);
	teste2=fcossin (VALOR2);
	aux=cos(2*VALOR2)+2*sin(VALOR2);
	printf("Valor calculado pelo computador:%lf\n",cos(2*VALOR2)+2*sin(VALOR2));
	printf("Valor encontrado: %lf\n",teste2);
	printf("Diferenca entre um e outro: %lf\n",fabs(aux-teste2));
	erroMax2= fcossin_erro (VALOR2);
	printf("Erro maximo possivel: %lf\n",erroMax2);
	return 0;
}