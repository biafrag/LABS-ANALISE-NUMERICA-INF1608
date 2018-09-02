double* Chebyshev (int n, double a, double b);

double* NewtonCoef (int n, double* xi, double (*f) (double));

double NewtonAval (int n, double* xi, double* bi, double x);