#include <stdio.h>
#include "bissecao.h"
#include <math.h>


double f1(double m)
{
	double c = 15;
	double g = 9.8;
	double t = 9;
	double v = (g*m / c)*(1 - exp((-c*t) / m)) - 35;
	return v;
}
double f2(double x)
{
	return 2 *x*x*x*x*x - 4 * x*x + 1;
}
double f3(double x)
{
	return sin(x) - 6 * x - 5;
}
double f4(double x)
{
	return tan(x) + 5 *x*x - x;
}
int main(void)
{
	double result;
	double *v1,*v2,*v3;
	int n, i;
	result = bissecao(0, 100, 5, f1);
	printf("Teste da bissecao numero 1: \n");
	printf("Resultado: %f\n\n", result);

	printf("Teste da bissecao multipla: \n\n");
	v1 = bissecao_multipla(-10, 10, 0.001, f2, &n);
	printf("Funcao 1:\n");
	printf("Quantidade de Raizes: %d\n", n);
	for (i = 0; i<n; i++)
	{
		printf("Raizes: %lf\n", v1[i]);
	}

	printf("\nFuncao 2:\n");
	v2 = bissecao_multipla(-10, 10, 0.001, f3, &n);
	printf("Quantidade de Raizes: %d\n", n);
	for (i = 0; i<n; i++)
	{
		printf("Raizes: %lf\n", v2[i]);
	}
	printf("\nFuncao 3\n");
	v3 = bissecao_multipla(-10, 10, 0.001, f4, &n);
	printf("Quantidade de Raizes: %d\n", n);
	for (i = 0; i<n; i++)
	{
		printf("Raizes: %lf\n", v3[i]);
	}
}