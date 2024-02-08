/*Author: MIDN Ronny Saini
 *Filename: rowshift.cpp
 *Move down the foreground image
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

  //get rowshift value
  cout << "Row shift: ";
  int rowShift;
  cin >> rowShift;

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

  
  if (rowShift+height1 > height2){
    cout << "Error: The foreground goes past the background" << endl;
    return 1;
  }

  fout << fHeader2 << endl << width2 << " " << height2 << endl << largeV2 << endl;

  //iterate through both images. In the bill picture if there is a 
  //green pixel replace it with the pixel from the other image
  int r1,g1,b1,r2,g2,b2;
  for (int i = 0; i < height2; i++){
    for (int j = 0; j < width2; j++){
        fin2 >> r2 >> g2 >> b2;
        
        if (i < rowShift){
          fout << r2 << " " << g2 << " " << b2 << " ";
        }
        
        else if (i > height1+rowShift){
          fout << r2 << " " << g2 << " " << b2 << " ";
        }
        
        else {
          if (j < width1){
            fin1 >> r1 >> g1 >> b1;
            if ((r1 == 0) && (g1 == 255) && (b1 == 0)){
            fout << r2 << " " << g2 << " " << b2 << " ";
            } else {
            fout << r1 << " " << g1 << " " << b1 << " ";
            }
            
          } 
          else {
          fout << r2 << " " << g2 << " " << b2 << " ";
          }
        }
    }
  }
  cout << "Image saved to " << ofName << endl;
  return 0;
  
}



