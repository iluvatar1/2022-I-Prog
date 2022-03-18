// Ejemplo de impresion a pantalla
#include <iostream> // incluye utilidades para imprimir y leer de pantalla
#include <cmath> // incluye utilidades para imprimir y leer de pantalla

//using namespace std; // mala practica

int main(void)
{
  std::cout << "Hola mundo\nHola clase\n" ;
  double result = 0; // must be double to store floating point values
  int n = 0;
  for(n = 1; n <= 100 ; n = n+1) {
    result = result + 1.0/n;
  }
  std::cout << result << "\n";
  return 0;
}

//
// std::sqrt(6*result)

// calcular el numero pi usando la aproximacion: sum 1/n^2 = pi^2/6
// e imprimir este numero para diferentes cantidad total de terminos
// en la suma
