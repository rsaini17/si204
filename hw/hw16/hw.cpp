/*Author: MIDN Ronny Saini
 *Filename: hw.cpp
 *Lowest Terms Fraction Checker
*/

#include <iostream>
using namespace std;

int gcd(int a, int b);

int main(){

  int a, b;
  char sign, comma;

  
  while (cin >> a >> sign >> b >> comma){
    if (comma == ';'){
      break;
    }
    if (gcd(a,b) == 1){
      cout << a << "/" << b << " is in lowest terms!" << endl;
    }
  }

  return 0;
}

int gcd(int a, int b){
   while(b != 0){
    int r = a % b;
    a = b;
    b = r;
   }
  return a;
}
