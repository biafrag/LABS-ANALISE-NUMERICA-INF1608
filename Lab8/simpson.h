double DoubleSimpson (double a, double b, double (*f) (double x), double* v);
double AdaptiveSimpson (double a, double b, double (*f) (double x), double tol);
double Quadratura2 (double a, double b, double (*f) (double x));
double Quadratura3 (double a, double b, double (*f) (double x));