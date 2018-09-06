#include <stdio.h>
#include "ode.h"
#include <math.h>
#define MIN(a,b) a<b?a:b 
double Euler (double t0, double t1, double h, double x0,
double (*f) (double t, double x))
{
	while(t1>t0)
	{
		x0=x0+h*f(t0,x0);
		t0=t0+h;
		h = MIN(h, t1 - t0);
	}
	//x0=x0+(t1-t0)*f(t0,x0);
	return x0;
}

double EulerAd (double t0, double t1, double h0, double x0,
double (*f) (double t, double x), double tol)
{
	double x1,xm,x2,e,fator;
	while(t0<t1)
	{
		x1=x0+h0*f(t0,x0);
		xm=x0+(h0/2)*f(t0,x0);
		x2=xm+(h0/2)*f(t0+(h0/2),xm);
		e=fabs(x1-x2);
		fator = pow((tol/e),0.5);
		if(fator < 1)
		{
			h0=MIN(h0*fator*0.9,t1-t0);
		}
		else
		{
			x0=x2 + (x2 - x1);
			t0=t0+h0;
			if(fator > 1.2)
			{
				fator = 1.2;
			}
			h0=MIN(h0*fator,t1-t0);
		}
	}

	return x2 + (x2 - x1);

}