#include <stdio.h>
#include <math.h>
#include "pendulo.h"
#define PI 3.1415
double pendulo (double t, double h, double* theta, double* w)
{
	double g=9.8;
	double l=10;
	double aux;
	*theta=*theta+h*(*w);

	*w=*w+h*((-g/l)*sin(*theta));
	t=t+h;

	return t;
}
double periodo (double theta_0)
{
	double theta=theta_0;
	double T=0;
	double t1=0;
	double t2=0;
	double w1=0;
	double w2=0;
	double h=pow(10.0,-3);
	int cont=0;
	theta=theta*PI/180;
	while(cont<10)
	{
		w1=w2;
		t1=t2;
		t2=pendulo (t1,h, &theta,&w2);
		if(w1*w2<0)
		{
			cont++;
		}
	}
	T=(2*(t1 +(fabs(w1)/(fabs(w1)+fabs(w2)))*(t2-t1)));
	return T/10;

}
double periodo_simplificado (void)
{
	return 2*PI*sqrt(10/9.8);
}