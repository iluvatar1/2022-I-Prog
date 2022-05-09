// g++ -g -fsanitize=address
#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  const int N = std::atoi(argv[1]);
  std::vector<double> data;
  data.reserve(5); //affects capacity, can store 15 numbers but its size is still 0
  data.resize(N); // real size, capacity >= N

  std::cout << "size: " << data.size() << std::endl;
  std::cout << "capacity: " << data.capacity() << std::endl;
  std::cout << "max_size: " << data.max_size() << std::endl;
  std::cout << "&data[0]: " << &data[0] << std::endl;
  std::cout << "&data[1]: " << &data[1] << std::endl;

  //std::cout << data[-1] << std::endl; // detected by sanitizers address

// initialize the array with even numbers
  int ii = 0;
  auto init  = [&ii](double & x){ x = 2*ii; ii++; };
  std::for_each(data.begin(), data.end(), init);

// print the array
  auto print = [](const double & x){ std::cout << x << "  ";};
  std::for_each(data.begin(), data.end(), print);
  std::cout << "\n";

// compute mean
  std::cout << "Average: " << std::accumulate(data.begin(), data.end(), 0.0)/data.size() << "\n";

// Add more data!
  std::cout << "size: " << data.size() << ", capacity: " << data.capacity() << std::endl;
  for (auto x : {200.0987, 300.987, 400.09754}){
    data.push_back(x);
    std::cout << "size: " << data.size() << ", capacity: " << data.capacity() << std::endl;
  }
  std::for_each(data.begin(), data.end(), print);
  std::cout << "\n";

  return 0;
}
