#include <iostream>
#include <fstream> // escribir o leer archivos
#include <cmath> // math functions

void gen_data(double xmin, double xmax, double dx, std::string fname);

int main(int argc, char **argv)
{
  const double XMIN = -M_PI/2;
  const double XMAX = +M_PI/2;
  const double DX = 0.01;
  const std::string FNAME = "data.txt";

  gen_data(XMIN, XMAX, DX, FNAME);
}

void gen_data(double xmin, double xmax, double dx, std::string fname)
{
  std::ofstream fout(fname);
  int nsteps = (xmax - xmin)/dx;
  for (int ii = 0; ii <= nsteps; ++ii){
    double x = xmin + ii*dx;
    fout << x << "\t" << std::sin(x) << "\n";
  }

  fout.close();
}
