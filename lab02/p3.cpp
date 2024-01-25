/*FileName: p3.cpp
 * Author: MIDN Ronny Saini
 * Unix permissions
 */
#include <iostream>
using namespace std;

int main(){

  char a,b,c;

  //get input from user
  cout << "Permissions: ";
  cin >> a >> b >> c;
  a = a - '0';
  b = b - '0';
  c = c - '0';

  //Convert dec digit to binary in other to get permissions:
  int x, y, z = 0;
  x = a%2;
  y = (a/2)%2;
  z = ((a/2)/2)%2;
  
  //print for user:
  cout << endl << "User:" << endl;
  cout << "read " << z << endl;
  cout << "write " << y << endl;
  cout << "execute " << x << endl;

  //repeat for group:
  x, y, z = 0;
  x = b%2;
  y = (b/2)%2;
  z = ((b/2)/2)%2;
  
  cout << endl << "Group:" << endl;
  cout << "read " << z << endl;
  cout << "write " << y << endl;
  cout << "execute " << x << endl;

  //repeat for Other: 
  x, y, z = 0;
  x = c%2;
  y = (c/2)%2;
  z = ((c/2)/2)%2;
  
  cout << endl << "Other:" << endl;
  cout << "read " << z << endl;
  cout << "write " << y << endl;
  cout << "execute " << x << endl;

  //return for function
  return 0;
}

