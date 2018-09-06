#include <stdio.h>
#include <math.h>
#include "simpson.h"

double DoubleSimpson (double a, double b, double (*f) (double x), double* v)
{
	double h,c;
	double Sab,Sac,Scb,Eab;
	h=b-a;
	c=(a+b)/2.0;
	Sab=(h/6)*(f(a)+4*f((a+b)/2)+f(b));
	Sac=(h/12)*(f(a)+4*f((a+c)/2)+f(c));
	Scb=(h/12)*(f(c)+4*f((c+b)/2)+f(b));
	Eab=(16.0/15.0)*fabs(Sab-Sac-Scb);
	*v=Sac+Scb+(Eab/16.0);
	return (Eab/16.0);
}
double AdaptiveSimpson (double a, double b, double (*f) (double x), double tol)
{
	double v;
	if(DoubleSimpson (a,b,f,&v)<tol)
	{
		return v;
	}
	return AdaptiveSimpson (a,(a+b)/2,f,tol/2) + AdaptiveSimpson ((a+b)/2,b,f,tol/2);
}
double Quadratura2 (double a, double b, double (*f) (double x))
{
	double integral;
	int i;
	integral=0;
    integral+=1*f(((b-a)*(-sqrt(1/3.0))+b+a)/2)*(b-a)/2;
	integral+=1*f(((b-a)*(sqrt(1/3.0))+b+a)/2)*(b-a)/2;
	return integral;
}
double Quadratura3 (double a, double b, double (*f) (double x))
{
	double integral;
	int i;
	integral=0;
	integral+=(5/9.0)*f(((b-a)*(-sqrt(3/5.0))+b+a)/2)*(b-a)/2;
	integral+=(8/9.0)*f(((b-a)*(0)+b+a)/2)*(b-a)/2;
	integral+=(5/9.0)*f(((b-a)*(sqrt(3/5.0))+b+a)/2)*(b-a)/2;
	return integral;
}