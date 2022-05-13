#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  const int M = 4;
  const int N = 3;

  std::vector<double> array2d(M*N, 0.0);
  for (int ii = 0; ii < M; ++ii) {
    for (int jj = 0; jj < N; ++jj) {
      //array2d[ii*N + jj] = 1.0/(ii+jj+1); // A_(i, j) = 1.0/(2i +j +1)
      array2d[ii*N + jj] = ii*N+jj; // A_(i, j) = 1.0/(2i +j +1)
    }
  }

  for (int ii = 0; ii < M; ++ii) {
    for (int jj = 0; jj < N; ++jj) {
      std::cout << array2d[ii*N + jj] << "  ";
    }
    std::cout << "\n";
  }

  // transpose matrix (ii, jj) -> (jj, ii)
  std::vector<double> array2d_T(M*N, 0.0);
  for (int ii = 0; ii < M; ++ii) {
    for (int jj = 0; jj < N; ++jj) {
      array2d_T[jj*M + ii] = array2d[ii*N + jj];
    }
  }

  for (int ii = 0; ii < N; ++ii) {
    for (int jj = 0; jj < M; ++jj) {
      std::cout << array2d_T[ii*M + jj] << "  ";
    }
    std::cout << "\n";
  }



  return 0;
}
