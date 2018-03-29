#include "raiz.h"
#include <stdio.h>
#include <math.h>
double f1(double x)
{
	return x+5;

}
double fl1(double x)
{
	return 1;
}
double f2(double x)
{
	return cos(x)-x*x*x+x;

}
double fl2(double x)
{
	return -sin(x)-3*x*x+1;
}
double f3(double x)
{
	return x*x-4;

}
double fl3(double x)
{
	return 2*x;
}
int main (void)
{
	double r;
	int it=NR(0,3, f1,fl1,&r);
	printf("COM O METODO DE NEWTON RAPHSON:\n");
	printf("Numero de iteracoes f1:%d\n",it);
	printf("Resultado ff1: %lf \n",r);
	it=NR(0,3, f2,fl2,&r);
	printf("Numero de iteracoes f2:%d\n",it);
	printf("Resultado f2: %lf \n",r);
	it=NR(1,6, f3,fl3,&r);
	printf("Numero de iteracoes f3:%d\n",it);
	printf("Resultado f3: %lf \n",r);
	printf("\nCOM O METODO DE IQI:\n");
	it=IQI (-1, 0, 2, 3,f1, &r);
	printf("Numero de iteracoes:%d\n",it);
	printf("Resultado: %lf \n",r);
	it=IQI (-1, 0, 2, 3,f2, &r);
	printf("Numero de iteracoes:%d\n",it);
	printf("Resultado: %lf \n",r);
	it=IQI (-1, 0, 2, 3,f3, &r);
	printf("Numero de iteracoes:%d\n",it);
	printf("Resultado: %lf \n",r);
	return 0;
}