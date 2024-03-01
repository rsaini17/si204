/*Author: MIDN Ronny Saini
 *Filename: hw.cpp
 *array display
*/
#include <iostream>
using namespace std;

// ======================================
// Function prototypes below
// ======================================
int readN();
int* readData(int N);
int show(int *A, int N);
int swap(int* A, int N);


// ======================================
// main function
// TOUCH NOTHING INSIDE THE FUNCTION!!
// ======================================
int main()
{
  int n = readN();
  int* A = readData(n);

  string cmd;
  cout << "cmd: ";
  while( (cin >> cmd) && cmd != "quit" ) 
  {
    if( cmd == "show" )
      show(A, n);
    else if ( cmd == "swap" )
      swap(A, n);

    cout << "cmd: ";
  }

  delete[] A;

  return 0;
}


// ======================================
// Function definitions below
// ======================================

int readN() {
    char junk;
    int N;
    cin >> junk >> junk >> N;
    return N;
}

int* readData(int n) {
    int* A = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    return A;
}

int show(int* A, int n) {
    for (int i = 0; i < n; i++) {
        cout << "[" << i << "] ";
        for (int j = 0; j < A[i]; j++)
            cout << "*";
        cout << endl;
    }
    return 0;
}

int swap(int* A, int n) {
    int i, j;
    cin >> i >> j;
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    return 0;
}
