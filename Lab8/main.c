#include <stdio.h>
#include <math.h>
#include "simpson.h"
#define PI 3.1415
double f1(double x)
{
	return (x/sqrt(x*x+9));
}

double f2(double x)
{
	return exp(-x*x/2);
}

double f3(double x)
{
	return exp(-x*x);
}
int main(void)
{
	double integral;
	printf("Testando Simpson Adaptativo:\n\n");
	integral=AdaptiveSimpson(0,1,f1,pow(10.0,-7));
	printf("Integral da primeira  : %.7g\n",integral);
	integral=AdaptiveSimpson(-1,1,f2,pow(10.0,-7));
	printf("Integral da segunda  : %.7g\n",(1/sqrt(2*PI))*integral);
	integral=AdaptiveSimpson(0,3,f3,pow(10.0,-7));
	printf("Integral da terceira  : %.7g\n\n",(2/sqrt(PI))*integral);
		
	printf("Testando Quadratura 2:\n\n");
	integral= Quadratura2 (0,1,f1);
	printf("Integral da primeira  : %.7g\n",integral);
	integral= Quadratura2 (-1,1,f2);
	printf("Integral da segunda  : %.7g\n",(1/sqrt(2*PI))*integral);
	integral= Quadratura2 (0,3,f3);
	printf("Integral da terceira  : %.7g\n\n",(2/sqrt(PI))*integral);

	printf("Testando Quadratura 3:\n\n");
	integral= Quadratura3 (0,1,f1);
	printf("Integral da primeira  : %.7g\n",integral);
	integral= Quadratura3 (-1,1,f2);
	printf("Integral da segunda  : %.7g\n",(1/sqrt(2*PI))*integral);
	integral= Quadratura3 (0,3,f3);
	printf("Integral da terceira  : %.7g\n\n",(2/sqrt(PI))*integral);

}