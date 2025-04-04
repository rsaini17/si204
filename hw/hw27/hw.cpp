#include <iostream>
using namespace std;

double pow(double, int);

int main()
{
  double x;
  int n;
  cout << "Enter x and n: ";
  cin >> x >> n;
  cout << "x^n is " << pow(x,n) << endl;
  return 0;
}

// Define pow: it must be recursive!
double pow(double x, int y){
  if(y == 0){
    return 1.0;
  }
  else {
    return x * pow(x, y-1);
  }
}
