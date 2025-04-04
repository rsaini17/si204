/*Author: MIDN Ronny Saini
 *Filename: p1.cpp
 *part 1 practicum
 */

#include <iostream>
using namespace std;

int readN();
double* readnums(int n, char* cA);
void reverse(double* A, double* B, char cA, char cB, int n);
void min(double* A, double* B, char cA, char cB, int n);

int main()
{

  //read N
  int n = readN();

  char cA, cB;
  //read the value of label and the first vector
  double* A = readnums(n, &cA);
  //read the value of second label and the second vector
  double* B = readnums(n, &cB);

  string cmd;
  while( cout << "> " && cin >> cmd && cmd != "quit" )
  {
    if( cmd == "reverse" )
      reverse(A, B, cA, cB, n);
    else if ( cmd == "min" )
      min(A, B, cA, cB, n);
    else
      cout << "invalid command!" << endl;
  }

  delete [] A;
  delete [] B;

  return 0;
}
  
int readN(){
  int r = 0;
  cin >> r;
  return r;
}

double* readnums(int n, char* cA){
  double* A = new double[n];
  char junk;
  cin >> *cA >> junk;
  for (int i = 0; i < n; i++){
    cin >> A[i];
  }
  return A;
}


void reverse(double* A, double* B, char cA, char cB, int n){
  char x;
  cin >> x;
  if(x == cA){
    cout << "[";
    for(int i = n-1; i > 0; i--)
      cout << A[i] << " ";
    cout << A[0] << "]" << endl;
  } else if(x == cB){
    cout << "[";
    for(int i = n-1; i > 0; i--)
      cout << B[i] << " ";
    cout << B[0] << "]" << endl;
  } else {
    cout << "no such vector!" << endl;
  }
}

void min(double* A, double* B, char cA, char cB, int n){
  char x;
  cin >> x;
  if(x == cA){
    double min = A[0];
    for (int i = 1; i < n; i++){
      if(A[i] < min){
        min = A[i];
      }
    }
    cout << min << endl;
  } else if(x == cB){
    double min = B[0];
    for (int i = 1; i < n; i++){
      if(B[i] < min){
        min = B[i];
      }
    }
    cout << min << endl;
  } else {
    cout << "no such vector!" << endl;
  }

}
