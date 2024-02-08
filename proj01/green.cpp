/*Author: MIDN Ronny Saini
 *Filename: green.cpp
 *Combine images
 */

#include <iostream>
#include <fstream>
using namespace std;

int main(){
  //get filenames from user:
  cout << "Foreground file: ";
  string foreFile;
  cin >> foreFile;
  ifstream fin1(foreFile);
  cout << "Background file: ";
  string backFile;
  cin >> backFile;
  ifstream fin2(backFile);

  //get output file
  cout << "Output file: ";
  string ofName;
  cin >> ofName;
  ofstream fout(ofName);

  //check if files don't exist
  if (!fin1 || !fin2){
    cout << "Error: Input file not found" << endl;
    return 1;
  }

  //read all the header information to check sizes
  string fHeader1;
  int width1, height1, largeV1;
  fin1 >> fHeader1 >> width1 >> height1 >> largeV1;

  string fHeader2;
  int width2, height2, largeV2;
  fin2 >> fHeader2 >> width2 >> height2 >> largeV2;

  if ((width1 != width2) || (height1 != height2)){
      cout << "Error: Images have different sizes" << endl;
      return 1;
  }

  fout << fHeader1 << endl << width1 << " " << height1 << endl << largeV1 << endl;

  //iterate through both images. In the bill picture if there is a 
  //green pixel replace it with the pixel from the other image
  int r1,g1,b1,r2,g2,b2;
  for (int i = 0; i < height1; i++){
    for (int j = 0; j < width1; j++){
        fin1 >> r1 >> g1 >> b1;
        fin2 >> r2 >> g2 >> b2;
        if ((r1 == 0) && (g1 == 255) && (b1 == 0)){
          fout << r2 << " " << g2 << " " << b2 << " ";
          } else {
          fout << r1 << " " << g1 << " " << b1 << " ";
      }
    }
  }
  cout << "Image saved to " << ofName << endl;
  return 0;
  
}


