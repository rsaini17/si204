/*Author: MIDN Ronny Saini
 *Filename: hw.cpp
 *Rectangle generator
*/
#include <iostream>
using namespace std;

int main(){

  //declare variables
  int height, width, offset;

  //user input 
  cout << "Enter height (greater than 2): ";
  cin >> height;
  cout << "Enter width (greater than 2): ";
  cin >> width;
  cout << "Enter offset: ";
  cin >> offset;
 
  //rectangle rows
  for (int i = 0; i < height; ++i){
    //offset
    for (int j = 0; j < offset; ++j){
      cout << " ";
    }
    //first or last row
    if (i == 0 || i == height - 1) {
      for (int j = 0; j < width; ++j) {
          cout << '*';
      }
    } //middle area
      else { 
        cout << '*';
        for (int j = 0; j < width - 2; ++j) {
          cout << ' ';
        }
        cout << '*';
    }
        
      cout << endl;
    }
  
  return 0;

}
