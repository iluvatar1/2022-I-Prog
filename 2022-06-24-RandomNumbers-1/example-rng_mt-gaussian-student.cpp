#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>
#include <vector>

int main(int argc, char **argv)
{
  if (5 != argc) {
    std::cerr << "Error. Usage:\n" << argv[0] << " SEED SAMPLES A B\n";
    return 1;
  }
  const int SEED = std::atoi(argv[1]);;
  const int SAMPLES = std::atoi(argv[2]);
  const int A = std::atof(argv[3]);;
  const int B = std::atof(argv[4]);

  std::mt19937 gen(SEED);
  //std::uniform_real_distribution<double> dist(A, B);
  std::normal_distribution<double> dist(A, B);
  std::ofstream fout("data.txt");
  for (int ii = 0; ii < SAMPLES; ++ii) {
    double r = dist(gen);
    fout << r << "\n";
  }
  fout.close();

  return 0;
}
