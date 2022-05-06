#include <cmath>
#include <iostream>
#include <vector>

double f(double x, const std::vector<double> &params);
double g(double x, const std::vector<double> &params);

template <typename func_t, typename par_t>
double newton(double x0, double eps, func_t func, const par_t &params, int nmax,
              int &nsteps);

int main(int argc, char *argv[]) {
  double X0 = std::atof(argv[1]);
  double eps = std::atof(argv[2]);
  int NMAX = 1000;
  std::cout.precision(15);
  std::cout.setf(std::ios::scientific);
  int steps = 0;

  // root for function f
  //                          M     G     VT    T
  std::vector<double> fparams{68.1, 9.81, 40.0, 10.0};
  double root = newton(X0, eps, f, fparams, NMAX, steps);
  std::cout << "\t" << root << "\t" << f(root, fparams) << "\t" << steps
            << "\n";

  // root for function g
  std::vector<double> gparams{1.234};
  root = newton(X0, eps, g, gparams, NMAX, steps);
  std::cout << "\t" << root << "\t" << g(root, gparams) << "\t" << steps
            << "\n";
}

double f(double x, const std::vector<double> &params) {
  return params[0] * params[1] * (1 - std::exp(-x * params[3] / params[0])) /
             x -
         params[2];
}

double g(double x, const std::vector<double> &params) {
  return std::exp(-params[0] * x) - x;
}
template <typename func_t, typename par_t>
double newton(double x0, double eps, func_t func, const par_t &params, int nmax,
              int &nsteps) {
  nsteps = 0;
  double xr = x0;
  while (nsteps <= nmax) {
    if (std::fabs(func(xr, params)) < eps) {
      break;
    } else {
      double h = 0.001;
      double deriv = (func(xr + h / 2, params) - func(xr - h / 2, params)) / h;
      xr = xr - func(xr, params) / deriv;
    }
    nsteps++;
  }

  return xr;
}
