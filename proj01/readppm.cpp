/*Author: MIDN Ronny Saini
 *Filename: readppm.cpp
 *Read ppm files
 */

#include <iostream>
#include <fstream>
using namespace std;

int main(){
  //get filename from user:
  cout << "Input file: ";
  string fName;
  cin >> fName;
  ifstream fin(fName);

  //read all the header information and print
  string fHeader;
  int width, height, largeV;
  fin >> fHeader >> width >> height >> largeV;

  cout << fHeader << endl << "width = " << width << ", height = " 
      << height << endl << "max value = " << largeV << endl;

  //using the height variable for the rows and width for columns
  //iterate through all the rgb values and print them.
  int r,g,b;

  for (int i = 0; i < height; i++){
      cout << "*** row " << i << " ***" << endl;
      for (int j = 0; j < width; j++){
        fin >> r >> g >> b;
        cout << "row " << i << ", col " << j << ": r" << r 
          << " g" << g << " b" << b << endl;
      }
  }

  return 0;
}
