/*Author: MIDN Ronny Saini
 *Filename: part4.cpp
 *out file to plot in spreadsheet
*/
#include <iostream>
#include <fstream>
using namespace std;

int main(){
  
  //input and output file names
  string filename, outFile;
  cin >> filename >> outFile;
  ifstream fin(filename);
  ofstream fout(outFile);
  
  //check to make sure file exists
  if (!fin){
    cout << "Could not open file '" << filename << "'" << endl;
    return 1;
  }

  //declare variables
  string junk, date, minD, maxD;
  double min = 0, max = 0, temp, total, count = 0;
  int hour;
  fin >> junk >> junk;
  
  //print out

  while (fin >> date >> hour >> junk >> temp){
    if (hour == 0){
      fout << date << "\t" << (9.0/5)*temp + 32 << "\t";
    } else if (hour == 23){
      fout << (9.0/5)*temp + 32 << endl;
    } else {
      fout << (9.0/5)*temp + 32 << "\t";
    }
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

  cout << "file: " << filename << endl << "ave: " << total << endl
    << "min: " << min << " on " << minD << endl
    << "max: " << max << " on " << maxD << endl << "output in: " 
    << outFile << endl;

  return 0;
}



