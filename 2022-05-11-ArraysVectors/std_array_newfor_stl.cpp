// g++ -g -fsanitize=address
#include <numeric>
#include <algorithm>
#include <iostream>
#include <array>

int main(void)
{
  const int N = 10;
  //double data[N] {0};
  std::array<double, N> data;

  std::cout << "size: " << data.size() << std::endl;
  std::cout << "max_size: " << data.max_size() << std::endl;
  std::cout << "&data[0]: " << &data[0] << std::endl;
  std::cout << "&data[1]: " << &data[1] << std::endl;

  //std::cout << data[-1] << std::endl; // detected by sanitizers address

// initialize the array with even numbers
  for(int ii = 0; ii < N; ++ii) {
    data[ii] = 2*ii;
  }

// print the array
  for(auto x : data){
    std::cout << x << "  ";
  }
  std::cout << "\n";

// compute mean
  double avg = std::accumulate(data.begin(), data.end(), 0.0)/data.size();
  std::cout << "Average = " << avg << std::endl;
}
