#include <iostream>
#include <cmath>
#include <cstdlib>

template <typename fptr>
double trapezoid_regular(double a, double b, int n, fptr func);

int main(int argc, char **argv)
{
  const int N = std::atoi(argv[1]);
  auto myfun = [](double x){return std::sin(x); };

  std::cout << "Regular integral (n = " << N << ") is : " << trapezoid_regular(0.0, M_PI, N, myfun) << std::endl;

  return 0;
}

template <typename fptr>
double trapezoid_regular(double a, double b, int n, fptr func)
{
  TODO
}
