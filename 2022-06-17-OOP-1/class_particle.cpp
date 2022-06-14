#include <valarray>
struct Particle {
  std::valarray<double> R{0, 0, 0}, V{0, 0, 0}, F{0, 0, 0};
  double mass{0};
};

int main(int argc, char **argv)
{
  Particle body1, body2;
  body1.R[0] = 5.6;
  body2.V[2] = -0.98;
  return 0;
}
