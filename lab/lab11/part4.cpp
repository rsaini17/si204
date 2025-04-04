/*Author: MIDN Ronny Saini
 *Filename: part4.cpp
 *Sierpinski Carpet
 */

#include <iostream>
#include <string>
using namespace std;

void repeat(string s, int count);
void carpet_row(int width, int row_index);

int main() {
  int size;
  cout << "size: ";
  cin >> size;

  cout << "Width-" << size << " Sierpinski carpet:" << endl;
  for (int i = 0; i < size; i++) {
    carpet_row(size, i);
    cout << endl;
  }
  return 0;
}

void repeat(string s, int count) {
  if (count == 0) {
    return;
  } else {
    cout << s;
    repeat(s, count - 1);
  }
}

void carpet_row(int width, int row_index) {
  string DIAMOND = "\u2bc1"; // Diamond symbol
  if (width == 1) {
    cout<< DIAMOND;    
  } 
  else {
    int partwidth = width / 3;
    int third = row_index / partwidth;
    if (third == 1) {
      carpet_row(partwidth, row_index % partwidth);
      repeat(" ", partwidth);
      carpet_row(partwidth, row_index % partwidth);
    } else {
      carpet_row(partwidth, row_index % partwidth);
      carpet_row(partwidth, row_index % partwidth);       
      carpet_row(partwidth, row_index % partwidth);
    }
  }     
}
