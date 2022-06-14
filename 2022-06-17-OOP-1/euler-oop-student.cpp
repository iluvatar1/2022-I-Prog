#include <fstream>
#include <iostream>
#include <cmath>
#include <valarray>
#include <numeric>
#include <string>

struct Particle {
  std::valarray<double> R{0, 0, 0}, V{0, 0, 0}, F{0, 0, 0};
  double mass{0};
};

void simulate(Particle & body, double dt, int nsteps, const std::string & fname);

int main(int argc, char *argv[]) {
  // simulation parameters
  if (argc != 4) {
    std::cerr << "Error.\n" << argv[0] << " DT NSTEPS MASS\n";
    std::exit(1);
  }
  const double DT = std::atof(argv[1]);
  const double NSTEPS  = std::atoi(argv[2]);
  const double MASS = std::atof(argv[3]);

  // Instance of particle
  Particle body1;
  body1.mass = MASS;
  // initial conditions
  body1.R = {0, 0, 4.3};
  body1.V = {0.123, 0.0, 0.98};

  // perform simulation
  simulate(body1, DT, NSTEPS, "datos.txt");

  return 0;
}

void simulate(Particle & body, double dt, int nsteps, const std::string & fname)
{
  // adapt me
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
