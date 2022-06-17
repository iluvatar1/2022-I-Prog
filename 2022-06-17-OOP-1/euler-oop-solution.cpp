#include <fstream>
#include <iostream>
#include <cmath>
#include <valarray>
#include <numeric>
#include <string>

struct Particle {
  std::valarray<double> R{0, 0, 0}, V{0, 0, 0}, F{0, 0, 0};
  double mass{0};
  Particle(){
    R = {0, 0, 0}; V = {0, 0, 0}; F = {0, 0, 0};
    mass = 0.0;
  }
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
  const std::valarray<double> G = {0, 0, -9.81};

  std::ofstream fout(fname);
  fout.precision(15); fout.setf(std::ios::scientific);

  for (int ii = 0; ii < nsteps; ++ii) {
    // compute force
    body.F = 0;
    body.F += body.mass*G;
    // apply Euler
    body.R = body.R + body.V*dt;
    body.V = body.V + body.F*dt/body.mass;
    // print
    fout << ii*dt << "\t" << body.R[0] << "\t" << body.R[1] << "\t" << body.R[2] << "\t"
         << body.V[0] << "\t" << body.V[1] << "\t" << body.V[2] << "\t"
         << body.F[0] << "\t" << body.F[1] << "\t" << body.F[2] << "\t"
         << "\n";
  }
  fout.close();

}
