#include <iostream>
#include <valarray>
#include <string>
#include <cmath>
#include <cstdlib>

typedef std::valarray<double> state_t; // alias for state type

void initial_conditions(state_t & y);
void print(const state_t & y, double time);
template <class deriv_t, class system_t, class printer_t>
void integrate_euler(deriv_t deriv, system_t & y, double tinit, double tend, double dt, printer_t writer);


int main(int argc, char **argv)
{
  if (argc != 5) {
    std::cerr << "ERROR. Usage:\n" << argv[0] << " T0 TF DT W" << std::endl;
    std::exit(1);
  }
  const double T0 = std::atof(argv[1]);
  const double TF = std::atof(argv[2]);
  const double DT = std::atof(argv[3]);
  const double W  = std::atof(argv[4]);
  const int N = 2;
  state_t y(N);
  initial_conditions(y);

  auto fderiv = [W](const state_t & y, state_t & dydt, double t){
    dydt[0] = y[1];
    dydt[1] = -W*W*y[0];
  };

  integrate_euler(fderiv, y, T0, TF, DT, print);

  return 0;
}

void initial_conditions(state_t & y)
{
  y[0] = 0.9876; // x
  y[1] = 0.0; // v
}

void print(const state_t & y, double time)
{
  std::cout << time << "\t" << y[0] << "\t" << y[1] << std::endl;
}

template <class deriv_t, class system_t, class printer_t>
void integrate_euler(deriv_t deriv, system_t & y, double tinit, double tend, double dt, printer_t writer)
{
  int N = y.size();
  system_t dydt(N, 0.0);
  double time = 0;
  int nsteps = (tend - tinit)/dt;
  for(int ii = 0; ii < nsteps; ++ii) {
    time = tinit + ii*dt;
    deriv(y, dydt, time);
    y = y + dydt*dt;
    print(y, time);
  }
}
