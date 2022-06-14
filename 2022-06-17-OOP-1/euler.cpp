#include <fstream>
#include <iostream>
#include <cmath>
#include <valarray>
#include <numeric>
#include <string>

typedef std::valarray<double> state_t;

void simulate(state_t & R, state_t & V, double dt, int nsteps, double mass, const std::string & fname);

int main(int argc, char *argv[]) {
  // initial conditions
  state_t R = {0, 0, 4.3}, V = {0.123, 0.0, 0.98};

  // simulation parameters
  if (argc != 4) {
    std::cerr << "Error.\n" << argv[0] << " DT NSTEPS MASS\n";
    std::exit(1);
  }
  const double DT = std::atof(argv[1]);
  const double N  = std::atoi(argv[2]);
  const double MASS = std::atof(argv[3]);

  // perform simulation
  simulate(R, V, DT, N, MASS, "datos.txt");

  return 0;
}

void simulate(state_t & R, state_t & V, double dt, int nsteps, double mass, const std::string & fname)
{
  state_t F = {0, 0, 0};
  const state_t G = {0, 0, -9.81};

  std::ofstream fout(fname);
  fout.precision(15); fout.setf(std::ios::scientific);

  for (int ii = 0; ii < nsteps; ++ii) {
    // compute force
    F = 0;
    F += mass*G;
    // apply Euler
    R = R + V*dt;
    V = V + F*dt/mass;
    // print
    fout << ii*dt << "\t" << R[0] << "\t" << R[1] << "\t" << R[2] << "\t"
         << V[0] << "\t" << V[1] << "\t" << V[2] << "\t"
         << F[0] << "\t" << F[1] << "\t" << F[2] << "\t"
         << "\n";
  }
  fout.close();
}
