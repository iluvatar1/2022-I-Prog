#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

template <typename fptr>
double trapezoid_regular(const double a, const double b, const int n, fptr func);
double trapezoid_irregular(const std::vector<double> & x, const std::vector<double> & fx);

int main(int argc, char **argv)
{
  const int N = std::atoi(argv[1]);
  auto myfun = [](double x){ return std::sin(x); };

  // test on-iregular (modelled as regular to compare)
  std::vector<double> x(N), f(N);
  for (int ii = 0; ii < N; ++ii) {
    x[ii] = 0 + ii*(M_PI-0)/N;
    f[ii] = myfun(x[ii]);
  }
  std::cout << "Non-regular integral is : " << trapezoid_irregular(x, f) << std::endl;

  // test on regular
  std::cout << "Regular integral (n = "<< N   << ") is : "
            << trapezoid_regular(0, M_PI, N, myfun) << std::endl;
  std::cout << "Regular integral (n = "<< 2*N << ") is : "
            << trapezoid_regular(0, M_PI, 2*N, myfun) << std::endl;

  return 0;
}

double trapezoid_irregular(const std::vector<double> & x, const std::vector<double> & fx)
{
  double sum = 0.0;
  for (int ii = 0; ii < x.size() - 1; ++ii) { // note the upper limit
    sum += (x[ii + 1] - x[ii])*(fx[ii] + fx[ii+1]);
  }
  return 0.5*sum;
}

template <typename fptr>
double trapezoid_regular(const double a, const double b, const int n, fptr func)
{
  const double h = (b-a)/n;
  double sum = 0.5*(func(a) + func(b));
  for(int ii = 1; ii < n-1; ++ii) { // note limits
    double x = a + ii*h;
    sum += func(x);
  }
  return h*sum;
}
