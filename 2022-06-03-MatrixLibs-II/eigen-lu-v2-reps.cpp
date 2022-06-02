#include <iostream>
#include <chrono>
#include <cmath>
#include <Eigen/Dense>

double solvesystem(int size);

int main(int argc, char ** argv)
{
  const int N = atoi(argv[1]); // Matrix size
  const int S = atoi(argv[2]); // Seed
  const int R = atoi(argv[3]); // Reps

  double sum = 0, sum2 = 0;
  double time = 0;
  for (int rep = 0; rep < R; ++rep) {
    srand(S+rep);
    time = solvesystem(N);
    sum  += time;
    sum2 += time*time;
  }
  double mean = sum/R;
  double sigma = std::sqrt(R*(sum2/R - mean*mean)/(R-1));

  std::cout.setf(std::ios::scientific); std::cout.precision(15);
  std::cout << N*N << "\t" << mean << "\t" << sigma << std::endl;

  return 0;
}

double solvesystem(int size)
{
  Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
  Eigen::MatrixXd b = Eigen::MatrixXd::Random(size, 1);

  auto start = std::chrono::steady_clock::now();
  Eigen::MatrixXd x = A.fullPivLu().solve(b);
  auto end   = std::chrono::steady_clock::now();

  std::chrono::duration<double> elapsed_seconds = end-start;
  return elapsed_seconds.count();
}
