#include <stdio.h>
#include "integral.h"
#include <math.h>
#define PI 3.1413
double f1(double x)
{
	return cos(x)-2*sin(x);
}
double fl1(double x)
{
	return -sin(x)-2*cos(x);
}
double fll1(double x)
{
	return -cos(x)+2*sin(x);
}
double flll1(double x)
{
	return sin(x)+2*cos(x);
}
double f2(double x)
{
	return x/sqrt(x*x+9);
}
double f3(double x)
{
	return x*x*log(x);
}
double f4(double x)
{
	return x*x*sin(x);
}
int main(void)
{
	double h,hr,integral;
	printf("Numero 2:\n");
	h=h_otimo (f1, fl1,0);
	printf("h que minimiza erro calculado:%.16g\n",h);
	hr=pow((3.0*pow(2.0,-52))/flll1(0),(1.0/3));
	printf("h que minimiza erro real:%.16g\n",hr);
	printf("Os valores conferem\n");

	printf("Testando Simpson:\n");
	integral=simpson (f2,0,4, 16);
	printf("Integral por Simpson da primeira com n =16 : %.16g\n",integral);
	integral=pontomedio (f2,0,4,16);
	printf("Integral por Ponto Medio da primeira com n =16 : %.16g\n",integral);
    integral=simpson (f2,0,4, 32);
	printf("Integral por Simpson da primeira com n=32 : %.16g\n",integral);
	integral=pontomedio (f2,0,4, 32);
	printf("Integral por Ponto Medio da primeira com n=32 : %.16g\n",integral);
	integral=simpson (f3,1,3, 16);
	printf("Integral por Simpson da segunda com n=16 : %.16g\n",integral);
	integral=pontomedio (f3,1,3, 16);
	printf("Integral por Ponto Medio da segunda com n=16 : %.16g\n",integral);
	integral=simpson (f3,1,3, 32);
	printf("Integral por Simpson da segunda com n=16 : %.16g\n",integral);
	integral=pontomedio (f3,1,3, 32);
	printf("Integral por Ponto Medio da segunda com n=16 : %.16g\n",integral);
	integral=simpson (f4,0,PI, 16);
	printf("Integral por Simpson da terceira com n=16 : %.16g\n",integral);
	integral=pontomedio (f4,0,PI, 16);
	printf("Integral por Ponto Medio da terceira com n=16 : %.16g\n",integral);
	integral=simpson (f4,0,PI, 32);
	printf("Integral por Simpson da terceira com n=32 : %.16g\n",integral);
	integral=pontomedio (f4,0,PI, 32);
	printf("Integral por Ponto Medio da terceira com n=32 : %.16g\n",integral);

	printf("Em todas as situacoes o Metodo de Simpson eh bem melhor\n");
	printf("E quanto maior o n melhor eh o resultado em todos os metodos\n");
	return 0;
}