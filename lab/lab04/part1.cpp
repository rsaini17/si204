/*Author: MIDN Ronny Saini
 *Filename: part1.cpp
 *more summarizing with min and max
*/
#include <iostream>
#include <fstream>
using namespace std;

int main(){
  
  //opening file name
  string filename;
  cin >> filename;
  ifstream fin(filename);
  
  //check to make sure file exists
  if (!fin){
    cout << "Could not open file '" << filename << "'" << endl;
    return 1;
  }

  //declare variables
  string junk;
  double temp, total, count = 0;
  fin >> junk >> junk;
  
  while (fin >> junk >> junk >> temp){
    total = total + temp;
    count++;
  }

  //find avg and then convert to F
  total = total/count;
  total = (9.0/5)*total + 32;

  cout << "file: " << filename << endl << "ave: " << total << endl;

  return 0;
}
