/*Author: MIDN Ronny Saini
 *Filename: hw.cpp
 *calspace
 */

#include <iostream>
using namespace std;

int calspace(int num);

int main()
{
  int n;
  cout << "Integer? ";
  cin >> n;

  cout << "#spaces= " << calspace(n) << endl;
  return 0;
}

int calspace(int num)
{
  if (num < 0) {
    return calspace(-num) + 1; // +1 for '-' sign
  } else if (num < 10) {
    return 1; // Single digit numbers require 1 space
  } else {
    return 1 + calspace(num / 10); // Add 1 for the last digit and recurse for the remaining digits
  }
}

