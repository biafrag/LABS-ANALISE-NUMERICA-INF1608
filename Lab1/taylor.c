#include <stdio.h>
#include "taylor.h"

double fsqrt (double x)
{
	//Através de calculos
	double result;
	double f1,f2,f3,f4;
	f1=1;
	f2=(1.0/2.0)*(x-1);
	f3=(-1.0/8.0)*(x-1)*(x-1);
	f4=(3.0/48.0)*(x-1)*(x-1)*(x-1);
	result=f1+f2+f3+f4;
	return result;
}

double fsqrt_erro (double x)
{
	double result;
	result=(5.0/128.0)*(x-1)*(x-1)*(x-1)*(x-1);
	return result;
}

double fcossin (double x)
{
    //Através de calculos
	double result;
	double f1,f2,f3,f4;
	f1=1;
	f2=2*x;
	f3=((-4.0)*x*x)/2.0;
	f4=((-2)*x*x*x)/6;
	result=f1+f2+f3+f4;
	return result;
}

double fcossin_erro (double x)
{
	double result;
	result=(x*x*x*x*16)/24;
	return result;
}