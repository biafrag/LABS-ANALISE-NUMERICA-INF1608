#include "raiz.h"
#include <math.h>
int NR (double x0, int p, double (*f) (double x),
double (*fl) (double x), double* r)
{
	double xi;
	int i;
	if(fabs(f(x0))<0.5*pow(10.0,-p))
	{
			*r=x0;
			return 0;
	}
	for(i=1;i<50;i++)
	{
		xi=x0-(f(x0)/fl(x0));
		if(fabs(f(xi))<0.5*pow(10.0,-p))
		{
			*r=xi;
			return i;
		}
		x0=xi;
	}
	return 0;
}

int IQI (double x0, double x1, double x2, int p,
double (*f) (double x), double* r)
{
	double fx1,fx2,fx0,c;
	double detAc,detA;
	int i;
	if(fabs(f(x0))<0.5*pow(10.0,-p))
	{
			*r=x0;
			return 0;
	}
	for(i=1;i<50;i++)
	{
		fx1=f(x1);
		fx2=f(x2);
		fx0=f(x0);
		detA=fx2*fx1*fx1+fx0*fx2*fx2+fx0*fx0*fx1-(fx1*fx2*fx2+fx0*fx0*fx2+fx0*fx1*fx1);
		if(detA==0)
		{
			return 0;
		}
		detAc=fx2*fx1*fx1*x0+fx0*fx2*fx2*x1+fx0*fx0*fx1*x2-(x0*fx1*fx2*fx2+fx0*fx0*fx2*x1+fx0*fx1*fx1*x2);
		c=detAc/detA;
		if(fabs(f(c))<0.5*pow(10.0,-p))
		{
			*r=c;
			return i;
		}
		x0=x1;
		x1=x2;
		x2=c;

	}
	return 0;
}