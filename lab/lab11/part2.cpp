/*Author: MIDN Ronny Saini
 *Filename: part2.cpp
 *Cantor Set
 */

#include <iostream>
#include <string>
using namespace std;


void repeat(string s, int count);

void cantor_row(int length);

int main() {
  int size;
  cout << "size: ";
  cin >> size;
  cout << "Width-" << size << " Cantor set:" << endl;
  cantor_row(size); 
  cout << endl;
  return 0;
}

void repeat(string s, int count) {
  if (count == 0){
    return;
  }
  else {
    cout << s;
    repeat(s, count-1);
  }
}

void cantor_row(int length) {
  if (length == 1) {
    cout << "X";    
  }
  else {
    cantor_row(length / 3);  
    repeat("_", length / 3);  
    cantor_row(length / 3);     
  }
}
