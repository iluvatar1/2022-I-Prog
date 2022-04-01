#include <iostream>
#include <fstream> // escribir o leer archivos

int main(int argc, char **argv)
{
  std::ofstream fout("data.txt");

  fout << 1 << "\tCADENA\n" << 3.56 << "\n";
  
  fout.close();
  
  return 0;  
}
