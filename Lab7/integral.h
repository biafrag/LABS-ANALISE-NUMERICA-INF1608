double derivada (double (*f) (double x), double x, double h);
double h_otimo (double (*f) (double x), double (*fl) (double x), double x);
double simpson (double (*f) (double), double a, double b, int n);
double pontomedio (double (*f) (double), double a, double b, int n);