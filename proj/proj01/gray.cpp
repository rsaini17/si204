/*Author: MIDN Ronny Saini
 *Filename: gray.cpp
 *Grayscale an image
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

  //get output file
  cout << "Output file: ";
  string ofName;
  cin >> ofName;
  ofstream fout(ofName);

  //check if file doesn't exist
  if (!fin){
    cout << "Error : Input file not found" << endl;
    return 1;
  }

  //read all the header information and print
  string fHeader;
  int width, height, largeV;
  fin >> fHeader >> width >> height >> largeV;

  fout << fHeader << endl << width << " " << height << endl << largeV << endl;

  //using the height variable for the rows and width for columns
  //iterate through all the rgb values and find the average.
  int r,g,b;
  for (int i = 0; i < height; i++){
      for (int j = 0; j < width; j++){
        fin >> r >> g >> b;
        int grey = (r+g+b)/3;
        fout << grey << " " << grey << " " << grey << " ";
      }
  }
  cout << "Image saved to " << ofName << endl;
  return 0;
}

