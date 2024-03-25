/*Author: MIDN Ronny Saini
 *Filename: hw.cpp
 *Matrix Checker
*/

#include <iostream>
using namespace std;


int main(){

  int row, col;
  char junk;
  cout << "What size? ";
  cin >> row >> junk >> col;

  int** A = new int*[row];
  for (int i = 0; i < row; i++){
    A[i] = new int[col];
  }

  for (int i = 0; i < row; i++){
    for (int j = 0; j < col; j++){
      int r;
      cin >> r;
      A[i][j] = r;
    }
  }

  int rowSum, colSum;
  cout << "rows: ";
  for (int i = 0; i < row; i++){
    rowSum = 0;
    for (int j = 0; j < col; j++){
      rowSum += A[i][j];
    }
    if (rowSum % 3 == 0){
      cout << i << " ";
    }
  }
  cout << endl << "cols: ";
  for (int i = 0; i < col; i++){
    colSum = 0;
    for (int j = 0; j < row; j++){
      colSum += A[j][i];
    }
    if (colSum % 3 == 0){
      cout << i << " ";
    }
  }
  cout << endl;

  for (int i = 0; i < row; i++){
    delete [] A[i];
  }
  delete [] A;

  return 0;
}
