/***************************************************
Filename: hw.cpp
Author: MIDN Ronny Saini (275580)
hw03 Work - Feet Inch Difference Calculator 
***************************************************/
#include <iostream>
using namespace std;

int main(){
  
  //declare variables
  int x, y, w, z;
  int holder1, holder2, difference;
  string a, b, c, d;

  //get user input
  cout << "Enter two lengths in feet and inches (larger first!)" << endl;
  cin >> x >> a >> y >> b;
  cin >> w >> c >> z >> d;

  //calculate difference: compute to inches then subtract
  holder1 = x*12 + y;
  holder2 = w*12 + z;
  difference = holder1 - holder2;

  //convert back into feet and inches and print statement
  cout << "Difference is " << difference/12 << "' " << difference%12 << "''" << endl;

  //return statement for function
  return 0;
}

