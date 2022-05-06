#include <iostream>
#include <cmath>
#include <vector>

double f(double x, double m, double g, double vt, double t);
double g(double x, double c);

template <typename func_t>
double newton(double x0, double eps, func_t func, int nmax, int & nsteps);

int main (int argc, char *argv[])
{
  double X0 = std::atof(argv[1]);
  double eps = std::atof(argv[2]);
  int NMAX = 1000;
  std::cout.precision(15); std::cout.setf(std::ios::scientific);
  int steps = 0;

  // root for function f
  double m = 68.1, g = 9.81, vt = 40.0, t = 10.0;
  auto flambda = [m, g, vt, t](double x){ return m*g*(1 - std::exp(-x*t/m))/x - vt; };
  double root = newton(X0, eps, flambda, NMAX, steps);
  std::cout << "\t" << root << "\t" << flambda(root) << "\t" << steps << "\n";

  // root for function g
  double c = 1.23;
  auto glambda = [c](double x){ return std::exp(-c*x) -  x; };
  root = newton(X0, eps, glambda, NMAX, steps);
  std::cout << "\t" << root << "\t" << glambda(root) << "\t" << steps << "\n";

}

template <typename func_t>
double newton(double x0, double eps, func_t func, int nmax, int & nsteps)
{
  nsteps = 0;
  double xr = x0;
  while(nsteps <= nmax) {
    if (std::fabs(func(xr)) < eps) {
      break;
    } else {
      double h = 0.001;
      double deriv = (func(xr + h/2) - func(xr-h/2))/h;
      xr = xr - func(xr)/deriv;
    }
    nsteps++;
  }

  return xr;
}
