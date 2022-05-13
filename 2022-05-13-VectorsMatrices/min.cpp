#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <cmath>

double min(const std::vector<double> & values);

int main(int argc, char **argv)
{
  // leer el tamano
  if (argc < 2) {
    std::cerr << "Por favor indicar el tamanho del vector:\n" << argv[0] << " VECTORSIZE\n";
    exit(1);
  }
  const int N = std::atoi(argv[1]);
  auto fprint = [](double x){ std::cout << x << "  "; };

  // declara el vector con ese tamanho
  std::vector<double> data;
  data.resize(N);

  // llenar el vector de alguna manera
  // a_i = 2i + 1
  int ii = 0;
  auto faux = [&ii](double & x){ x = 2*ii + 1; ii++; };
  std::for_each(data.begin(), data.end(), faux);
  std::for_each(data.begin(), data.end(), fprint);
  std::cout << "\n";

  // calcular el minimo
  std::cout << "minval" << min(data) << "\n";

  return 0;
}
double min(const std::vector<double> & values)
{
  double minval = values[0];
  for (auto x: values) {
    if (x < minval) {
      minval = x;
    }
  }
  return minval;
}
