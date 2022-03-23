#include <iostream> // incluye utilidades para imprimir y leer de pantalla
#include <cmath> // incluye utilidades para imprimir y leer de pantalla

// function declaration: What is it
int isprime(int n);

int main(void)
{
  int m = 50;
  std::cout << m << "\t" << isprime(m) << "\n";
  m = 51;
  std::cout << m << "\t" << isprime(m) << "\n";
  m = 73;
  std::cout << m << "\t" << isprime(m) << "\n";
  return 0;
}

// function implementation: How to do it
int isprime(int n)
{
  int result = 1;
  for(int ii = 2; ii <= std::sqrt(n)+1; ii++) {
    if (n%ii == 0) {
      result = 0;
    }
  }
  return result;
}
