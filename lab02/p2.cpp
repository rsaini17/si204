/*Filename: p2.cpp
 *Author: MIDN Ronny Saini
 *Converting Back to Binary
 */
#include <iostream>
using namespace std;

int main(){

  //declare variables
  int x,a,b,c,d;

  //ask user for input
  cout << "Enter a number between 0 and 15: ";
  cin >> x;

  //repeat 4 times:mod2 to see if base present to get digit, then divide by 2. Reverse quotients at the end. 
  a = x%2;
  b = (x/2)%2;
  c = ((x/2)/2)%2;
  d = (((x/2)/2)/2)%2;
  
  //print to user
  cout << x << " in binary is " << d << c << b << a << endl;  

  //function return
  return 0;
}
