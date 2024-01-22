#include <iostream>
using namespace std;

int main(){

  double a;
  int b;
  char c;
  a = 16.4;
  b = 3;
  c = 4*a+b;

  cout << a+b << endl;
  cout << static_cast<char>(a) + b << endl;
  cout << static_cast<char>(b) - static_cast<char>(a) << endl;
  cout << a/4 << endl;
  cout << b/4 << endl;
  cout << b%4 << endl;
  cout << c << endl;
  cout << int(c) << endl;
  b = a;
  cout << b << endl;

  return 0;
}
