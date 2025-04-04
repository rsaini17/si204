/*Author: MIDN Ronny Saini
 *Filename: part2.cpp
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
  string junk, date, minD, maxD;
  double min = 0, max = 0, temp, total, count = 0;
  fin >> junk >> junk;
  
  while (fin >> date >> junk >> temp){
    total = total + temp;
    count++;
    if (temp < min){
      minD = date;
      min = temp;
    }
    if (temp > max){
      maxD = date;
      max = temp;
    }
  }

  //find avg and then convert to F
  total = total/count;
  total = (9.0/5)*total + 32;
  min = (9.0/5)*min + 32;
  max = (9.0/5)*max + 32;

  cout << "file: " << filename << endl << "ave: " << total 
    << endl << "min: " << min << " on " << minD << endl
    << "max: " << max << " on " << maxD << endl;

  return 0;
}

