/*Filename: p1.cpp
 *Author: MIDN Ronny Saini
 *
 *Reading binary numbers
 */
#include <iostream> 
using namespace std;

int main(){

  //declare variables
  char a,b,c,d;
  int total = 0;

  //ask user for input
  cout << "Enter a 4-bit binary number: ";
  cin >> a >> b >> c >> d;

  //calculate total by finding sum of all bases and digits
  
  total = (a-48)*8 + (b-48)*4 + (c-48)*2 + (d-48)*1;

  cout << "In decimal " << a << b << c << d << " = " << total << endl;
  
  //function return
  return 0;
}
