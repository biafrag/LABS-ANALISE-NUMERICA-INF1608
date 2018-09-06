#include <stdio.h>
#include <math.h>
double derivada (double (*f) (double x), double x, double h)
{
	double deriv;
	deriv=(f(x+h)-f(x-h))/(2*h);
	return deriv;
}
double h_otimo (double (*f) (double x), double (*fl) (double x), double x)
{
	int i;
	double erro,h,menorh,erromenor,flx;
	menorh=pow(10.0,-1);
	erromenor=fabs(fl(x)-derivada(f,x,menorh));
	flx=fl(x);
	for(i=2;i<13;i++)
	{
		h=pow(10.0,-i);
		erro=fabs(flx-derivada(f,x,h));
		if(erromenor>erro)
		{
			erromenor=erro;
			menorh=h;

		}
	}
	return menorh;
}

double simpson (double (*f) (double), double a, double b, int n)
{
	double h,integral;
	double xi,f1,f2,f3;
	int i;
	h=(b-a)/n;
	xi=a;
	integral=0;
	f1=f(xi);
	for(i=0;i<n;i++)
	{
		f2=f(xi+(h/2));
		f3=f(xi+h);
		integral+=(h/6)*(f1+4*f2+f3);
		f1=f3;
		xi=xi+h;
	}
	return integral;
}
double pontomedio (double (*f) (double), double a, double b, int n)
{
	double h,wi,integral;
	int i;
	h=(b-a)/n;
	integral=0;
	for(i=0;i<n;i++)
	{
		wi=a+(h/2);
		integral+=h*f(wi);
		a=a+h;
	}
	return integral;
}