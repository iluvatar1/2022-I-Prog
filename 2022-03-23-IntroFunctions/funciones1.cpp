#include <iostream> // incluye utilidades para imprimir y leer de pantalla
#include <cmath> // incluye utilidades para imprimir y leer de pantalla

// function declaration: What is it
double suma(int nterms);

int main(void)
{
  int NMAX = 50;
  std::cout << NMAX << "\t" << suma(NMAX) << "\n";
  NMAX = 100;
  std::cout << NMAX << "\t" << suma(NMAX) << "\n";
  return 0;
}

// function implementation: How to do it
double suma(int nterms)
{
  double result = 0; // must be double to store floating point values
  for(int n = 1; n <= nterms ; n += 1) { // n+=1 -> n = n+1 -> n++
    result += 1.0/n; // result = result + 1.0/n;
  }
  return result;
}
