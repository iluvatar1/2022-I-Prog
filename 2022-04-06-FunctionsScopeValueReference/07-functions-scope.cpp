// function example
#include <iostream>

int addition (int a, int b);

int main (int argc, char **argv)
{
  int c{0}, a{0}, b{0};
  a = 5; // is this a the same that is declared in addition?
  b = 3; // is this b the same that is declared in addition?
  c = addition (a, b);
  std::cout << "The result is " << c;
  return 0;
}

int addition (int a, int b)
{
  int r = 0;
  r = a + b;
  return r;
}
