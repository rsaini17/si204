/*Author: MIDN Ronny Saini
 *Filename: part1.cpp 
 *Game
 */

#include <iostream>
#include <fstream>
using namespace std;

int main (){
  
  //declare variables
  string board, junk;
  int col, row = 0;
  char value, junk2;

  //user input
  cin >> board;
  ifstream fin(board);

  if (!fin){
    cout << "File not found!" << endl;
    return 1;
  }

  int width;
  fin >> junk >> junk >> width;
  
  cout << "Enter position between 1 and " << width << ": ";
  cin >> col; 
  
  if (col < 1 || col > width){
    cout << "Invalid position!" << endl;
    return 1;
  }

  //iterate through the board, while there is another row
  //junk the first and last @ char, and iterate through the
  //width until the right column and then check if there is 
  //and X there.
  while (fin){
    row++;
    fin >> junk2; 
    for (int i = 1; i <= width; i++){
      fin >> value;
      if (i == col){
        if (value == 'X'){
          cout << "You died on step " << row << endl;
          return 1;
        }
      }
    }
    fin >> junk2;
  }
  
  cout << "You survived!" << endl;

  return 0;
}
