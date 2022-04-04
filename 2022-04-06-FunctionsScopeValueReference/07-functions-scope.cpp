// function example 
#include <iostream> 

int addition (int a, int b) 
{ 
  int r; 
  r = a + b; 
  return r; 
} 
     
int main (void) 
{ 
  int c, a, b;
  a = 5;
  b = 3; 
  c = addition (a, b); 
  std::cout << "The result is " << c; 
  return 0; 
}
