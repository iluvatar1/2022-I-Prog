// function example
#include <iostream>
#include <cstdlib>

int main (int argc, char **argv)
{
  const int A = std::atoi(argv[1]);
  const double B = std::atof(argv[2]);
  std::cout << A+B << "\n";
}
