#include <math.h>
#include <stdio.h>
#include "ode.h"
int contador=0;
double f(double t, double x)
{
	contador++;
	return t*x + t*t*t;
}

double y(double t)
{
	return exp(t*t/2)-t*t-2;
}

int main (void)
{
	double xt1,erro;
	contador=0;
	printf("Para 0.1:\n\n");
	printf("Resultado Real: %lf\n\n",y(2.4));
	xt1 = Euler (0,2.4,0.1, -1,f);
	erro=fabs(xt1-y(2.4))/xt1;
	printf("Resultado Euler: %lf\n",xt1);
	printf("Quantidade de avaliacoes da derivada: %d\n",contador);
	contador=0;
	xt1 = EulerAd (0, 2.4,0.1, -1,f, 0.1);
	printf("Erro relativo Euler: %lf\n",erro);
	erro=fabs(xt1-y(2.4))/xt1;
	printf("Resultado Euler Adaptativo: %lf\n",xt1);
	printf("Quantidade de avaliacoes da derivada: %d\n",contador);
	printf("Erro relativo Euler Adaptativo: %lf\n\n",erro);
	contador=0;
	
	printf("Para 0.01:\n\n");
	printf("Resultado Real: %lf\n\n",y(2.4));
	xt1 = Euler (0,2.4,0.01, -1,f);
	erro=fabs(xt1-y(2.4))/xt1;
	printf("Resultado Euler: %lf\n",xt1);
	printf("Quantidade de avaliacoes da derivada: %d\n",contador);
	printf("Erro relativo Euler: %lf\n",erro);
	contador=0;
	xt1 = EulerAd (0, 2.4,0.01, -1,f, 0.01);
	erro=fabs(xt1-y(2.4))/xt1;
	printf("Resultado Euler Adaptativo: %lf\n",xt1);
	printf("Quantidade de avaliacoes da derivada: %d\n",contador);
	printf("Erro relativo Euler Adaptativo: %lf\n\n",erro);
	contador=0;

	printf("Para 0.001:\n\n");
	printf("Resultado Real: %lf\n\n",y(2.4));
	xt1 = Euler (0,2.4,0.001, -1,f);
	erro=fabs(xt1-y(2.4))/xt1;
	printf("Resultado Euler: %lf\n",xt1);
	printf("Quantidade de avaliacoes da derivada: %d\n",contador);
	printf("Erro relativo Euler: %lf\n",erro);
	contador=0;
	xt1 = EulerAd (0, 2.4,0.001, -1,f, 0.001);
	erro=fabs(xt1-y(2.4))/xt1;
	printf("Resultado Euler Adaptativo: %lf\n",xt1);
	printf("Quantidade de avaliacoes da derivada: %d\n",contador);
	printf("Erro relativo Euler Adaptativo: %lf\n\n",erro);
}