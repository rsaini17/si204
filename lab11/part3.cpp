/*Author: MIDN Ronny Saini
 *Filename: part3.cpp
 *Full Cantor Set
 */

#include <iostream>
#include <string>
using namespace std;


void repeat(string s, int count);

void cantor_row(int length, int levels);

int main() {
  int size;
  cout << "size: ";
  cin >> size;

  //check number of lines needed
  int lines = 0;
  int x = size;
  while (x > 0) {
    x /= 3;
    lines++;
  }

  cout << "Width-" << size << " Cantor set:" << endl;
  for (int i = 0; i < lines; ++i) {
    cantor_row(size, i);
    cout << endl;
  }

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

void cantor_row(int width, int levels) {
  if (levels == 0) {
    repeat("X", width);
  } else if (width > 1) {
    cantor_row(width / 3, levels - 1);
    repeat("_", width / 3);
    cantor_row(width / 3, levels - 1);
  }
}
