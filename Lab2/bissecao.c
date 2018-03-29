#include <stdio.h>
#include "bissecao.h"
#include <math.h>
#include <malloc.h>
double bissecao(double a, double b, int p, double(*f) (double x))
{
	int i = 0;
	double aux;
	double c;
	double Fc;
	double Fa;
	int n;
	aux = (log((b - a) / (0.5*pow(10.0, -p))) / log(2.0)) - 1;
	n = ceil(aux);
	Fa = f(a);
	while (i<n)
	{
		c = (a + b) / 2;
		Fc = f(c);
		if (fabs(Fc - 0)<pow(10.0, -14))
		{
			return c;
		}
		if (Fa*Fc<0)
		{
			b = c;
		}
		else
		{
			Fa = Fc;
			a = c;
		}
		i++;
	}
	return c;
}

double* bissecao_multipla(double A, double B, double delta,
	double(*f) (double x), int* n)
{
	double *v;
	double i1, i2;
	double value;
	int i;
	int pos = 0;
	int numero = 0;
	for (i = 0; (A + delta*(i + 1))<B; i++)
	{
		i1 = A + (delta*i);
		i2 = A + (delta*(i + 1));
		value = f(i1)*f(i2);
		if (value<0)
		{
			numero++;
		}
	}
	v = (double*)malloc(sizeof(double)*numero);

	for (i = 0; (A + delta*(i + 1))<B; i++)
	{
		i1 = A + (delta*i);
		i2 = A + (delta*(i + 1));
		value = f(i1)*f(i2);
		if (value<0)
		{
			v[pos] = bissecao(i1, i2, 5, f);
			pos++;
		}
	}
	*n = numero;
	return v;

}