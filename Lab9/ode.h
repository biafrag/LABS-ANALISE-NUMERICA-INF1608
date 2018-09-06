double Euler (double t0, double t1, double h, double x0,
double (*f) (double t, double x));

double EulerAd (double t0, double t1, double h0, double x0,
double (*f) (double t, double x), double tol);