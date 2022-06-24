#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>
#include <vector>

int main(int argc, char **argv)
{
  if (8 != argc) {
    std::cerr << "Error. Usage:\n" << argv[0] << " SEED SAMPLES A B XMIN XMAX NBINS\n";
    return 1;
  }
  const int SEED = std::atoi(argv[1]);
  const int SAMPLES = std::atoi(argv[2]);
  const int A = std::atof(argv[3]);
  const int B = std::atof(argv[4]);
  const double XMIN = std::atof(argv[5]);
  const double XMAX = std::atof(argv[6]);
  const int NBINS = std::atoi(argv[7]);
  const double DX = (XMAX-XMIN)/NBINS;

  std::vector<double> histo(NBINS, 0.0);
  std::mt19937 gen(SEED);
  //std::uniform_real_distribution<double> dist(A, B);
  std::normal_distribution<double> dist(A, B);
  std::ofstream fout("data.txt");
  for (int ii = 0; ii < SAMPLES; ++ii) {
    double r = dist(gen);
    fout << r << "\n";
    int bin = int((r - XMIN)/DX); // compute the bin where the sample lies
    if (0 <= bin && bin < NBINS) { // check if the bin is included
      histo[bin]++; // increase the counter in that bin
    }
  }
  fout.close();

  fout.open("histo.txt");
  for (int ii = 0; ii < NBINS; ii++) {
    fout << XMIN + ii*DX << "\t" << histo[ii]/(DX*SAMPLES) << "\n";
  }
  fout.close();

  return 0;
}
