#include <iostream>
#include <cstdio>
#include <cmath>

using fptr = double(double);

double f(double x);
double g(double x);
double forward_deriv(double x, double h, fptr fun);
double central_deriv(double x, double h, fptr fun);
double richardson_deriv(double x, double h, int order, fptr fun);

int main(void)
{
  double h, x, df, dc, dr, dexact;

  x = 3.7;
  for (int ii = 1; ii <= 10; ii++) {
    h = std::pow(10.0, -ii);
    df = forward_deriv(x, h, g); // pointer allows to deriv other functions: forward_deriv(x, h, std::cos)
    dc = central_deriv(x, h, g);
    dr = richardson_deriv(x, h, 2, g);
    //dexact = 2*std::cos(2*x);
    dexact = -2*std::sin(2*x);
    std::printf("%25.16e%25.16e%25.16e%25.16e\n", h,
                std::fabs(df-dexact)/dexact,
                std::fabs(dc-dexact)/dexact,
                std::fabs(dr-dexact)/dexact);
  }

  return 0;
}

double f(double x)
{
  return std::sin(2*x);
}

double g(double x)
{
  return std::cos(2*x);
}

double forward_deriv(double x, double h, fptr fun)
{
  return (fun(x+h) - fun(x))/h;
}

double central_deriv(double x, double h, fptr fun)
{
  return (fun(x + h/2) - fun(x - h/2))/h;
}

double richardson_deriv(double x, double h, int order, fptr fun)
{
  const double C = std::pow(2, order);
  double f1, f2;
  f1 = central_deriv(x, h, fun);
  f2 = central_deriv(x, h/2, fun);
  return (C*f2 - f1)/(C-1);
}
