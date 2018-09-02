#include <stdio.h>
#include <math.h>
#include "interp.h"
#define PI 3.1413
int main(void)
{
	int i;
	double*v;
	double* bi;
	double result;
	double erro;
	printf("Testando com cos(x)\n");
	printf("Testando Chebyshev\n");
	v=Chebyshev (6, 0, PI/2);
	for(i=0;i<6;i++)
	{
		printf("X[%d]=%lf\n",i,v[i]);
	}
	bi=NewtonCoef (6, v,cos);
	result=NewtonAval (6,v,bi,PI/2);
	printf("Resultado da aproximacao:%lf\n",result);
	printf("Resultado da funcao:%lf\n",cos(PI/2));
	erro=(pow(((PI-0)/2),6)*(-cos(0.0)))/(pow(2.0,6-1)*6*5*4*3*2);
	printf("Erro maximo:%lf\n",erro);

}