#include "vetmat.h"
#include <malloc.h>
#include <math.h>
double* vetcria (int n) //1
{
	double *v;
	v=(double*)malloc(sizeof(double)*n);
	return v;
}

void vetlibera (double* v) //2
{
	free(v);
}

double escalar (int n, double* v, double* w) //3
{
	int i;
	double result=0;
	for(i=0;i<n;i++)
	{
		result+=v[i]*w[i];
	}
	return result;
}

double norma2 (int n, double* v) //4
{
	int i;
	double norm=0;
	for(i=0;i<n;i++)
	{
		norm+=pow(v[i],2);
	}
	return sqrt(norm);
}

int vetiguais (int n, double* v, double* w, double tol) //5
{
	int i;
	for(i=0;i<n;i++)
	{
		if(fabs(v[i]-w[i])>tol)
		{
			return 0;
		}
	}
	return 1;
}

void vetimprime (int n, double* v, char* format) // 6) Ex: "%.7g","%f
{
	int i;
	for(i=0;i<n;i++)
	{
		printf(format,v[i]);
		printf("\n");
	}
}

double** matcria (int m, int n) //7
{
	double **M;
	int i;
	M=(double**)malloc(sizeof(double*)*m);
	for(i=0;i<m;i++)
	{
		M[i]=vetcria(n);
	}

	return M;
}

void matlibera (int m, double** A) //8
{
	int i;
	for(i=0;i<m;i++)
	{
		free(A[i]);
	}
	free(A);
}

void transposta (int m, int n, double** A, double** T) //9
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			T[j][i]=A[i][j];
		}
	}
}

void multmv (int m, int n, double** A, double* v, double* w) //10
{
	int i,j;
	for(i=0;i<m;i++)
	{
		w[i]=0;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			w[i]+=A[i][j]*v[j];
		}
	}

}

void multmm (int m, int n, int q, double** A, double** B, double** C) //11
{
	int i,j,k;
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
		{
			C[i][j]=0;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
		{
			for(k=0;k<n;k++)
			{
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
}

int matiguais (int m, int n, double** A, double** B, double tol) //12
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(fabs(A[i][j]-B[i][j])>tol)
			{
				return 0;
			}
		}
	}
	return 1;
}

void matimprime (int m, int n, double** A, char* format) //13
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf(format,A[i][j]);
			printf(" ");
		}
		printf("\n");
	}
}