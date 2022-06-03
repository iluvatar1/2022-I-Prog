#include <iostream>
#include <chrono>
#include <Eigen/Dense>


void solvesystem(int size);

int main(int argc, char ** argv)
{
  const int M = atoi(argv[1]); // Matrix size
  const int S = atoi(argv[2]); // seed
  srand(S); // control the seed

  solvesystem(M);
}

void solvesystem(int size)
{
  Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
  Eigen::MatrixXd b = Eigen::MatrixXd::Random(size, 1);

  auto start = std::chrono::steady_clock::now();
  Eigen::MatrixXd x = A.fullPivLu().solve(b);
  auto end   = std::chrono::steady_clock::now();

  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << size*size << "\t" << elapsed_seconds.count() << "\t" << x(0) << std::endl;
}
