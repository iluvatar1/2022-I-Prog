// factorial calculator
#include <iostream>

long factorial (long a)
{
  if (a > 1)
    return (a * factorial (a-1));
  else
    return 1;
}

int main ()
{
  long number = 9;
  std::cout << number << "! = " << factorial (number);
  return 0;
}
