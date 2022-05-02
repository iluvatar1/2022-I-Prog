#include <iostream>
#include <cmath>
#include <vector>

struct Functor_f {
  double M = 68.1, G = 9.81, VT = 40.0, T = 10.0;
  double operator()(double x) {
      return M*G*(1 - std::exp(-x*T/M))/x - VT;
    }
  };

struct Functor_g {
  double C = 1.234;
  double operator()(double x) {
      return std::exp(-C*x) - x;
    }
  };

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
  Functor_f f;
  double root = newton(X0, eps, f, NMAX, steps);
  std::cout << "\t" << root << "\t" << f(root) << "\t" << steps << "\n";

  // root for function g
  Functor_g g;
  root = newton(X0, eps, g, NMAX, steps);
  std::cout << "\t" << root << "\t" << g(root) << "\t" << steps << "\n";

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
