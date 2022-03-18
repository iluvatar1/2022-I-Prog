// Ejemplo de impresion a pantalla
#include <iostream> // incluye utilidades para imprimir y leer de pantalla
#include <cmath> // incluye utilidades para imprimir y leer de pantalla

//using namespace std; // mala practica

int main(void)
{
  double result = 0; // must be double to store floating point values
  int NMAX = 10000;
  int n = 0;
  for(n = 1; n <= NMAX ; n = n+1) {
    result = result + 1.0/n;
    std::cout << n << "\t" << result << "\n";
  }
  //std::cout << NMAX << "\t" << result << "\n";
  return 0;
}

//
// std::sqrt(6*result)

// calcular el numero pi usando la aproximacion: sum 1/n^2 = pi^2/6
// e imprimir este numero para diferentes cantidad total de terminos
// en la suma
