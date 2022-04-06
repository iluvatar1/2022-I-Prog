// factorial calculator
#include <iostream>
#include <cstdlib>

long factorial (long a);

int main (int argc, char **argv)
{
  long number = std::atoi(argv[1]);
  std::cout << number << "! = " << factorial (number) << "\n";
  return 0;
}

long factorial (long a)
{
  if (a > 1)
    return (a * factorial (a-1));
  else
    return 1;
}
