/*Author: MIDN Ronny Saini
 *Filename: p3.cpp
 *Part 3 Prac
*/

#include <iostream>
using namespace std;

int main(){

  int street, avenue;
  string junk;
  cin >> street >> junk >> avenue >> junk;

  
  int** A = new int*[street];
  for (int i = 0; i < street; i++){
    A[i] = new int[avenue];
  }

  
  for (int i = 0; i < street; i++){
    for (int j = 0; j < avenue; j++){
      A[i][j] = 0;
    }
  }

  A[1][0] = 1;
  A[2][4] = 4;
  A[5][0] = 1;
  A[7][2] = 3;

  for (int i = 0; i < street; i++){
    for (int j = 0; j < avenue; j++){
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
  
  string cmd;
  while( cout << "> " && cin >> cmd && cmd != "quit" ){
    int street2, avenue2;
    cin >> street2 >> junk >> junk >> avenue2 >> junk;
    A[street2-1][avenue2-1] += 1;

  for (int i = 0; i < street; i++){
    for (int j = 0; j < avenue; j++){
      cout << A[i][j] << " ";
    }
    cout << endl;
  }

  }
}
