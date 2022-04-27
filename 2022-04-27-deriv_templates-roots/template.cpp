#include <iostream>
#include <string>
#include <typeinfo> // get typeinformation

template <typename gen_t>
void dosomething(gen_t a);

int main(int argc, char *argv[]) {
  int a = 9;
  float b = 0.98;
  double c = -0.98e4;
  char d = 'd';
  std::string str = "Hola Mundo";

  dosomething(a);
  dosomething(b);
  dosomething(c);
  dosomething(d);
  dosomething(str);

  return 0;
}


template <typename gen_t>
void dosomething(gen_t a)
{
  std::cout << "Type is: " << typeid(a).name() << "\n";
}
