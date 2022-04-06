// function example
#include <iostream>

int addition (int a, int b);

int main (int argc, char **argv)
{
  int z, x, y;
  x = 5;
  y = 3;
  z = addition (x,y);
  std::cout << "The result is " << z << "\n";
  std::cout << "The value of x is " << x << "\n";
  return 0;
}

int addition (int a, int b)
{
  int r = 0;
  r = a + b;
  a = r;
  return r;
}
