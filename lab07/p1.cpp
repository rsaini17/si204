/*Author: MIDN Ronny Saini
 *Filename: p1.cpp
 *Array Functions
 */

#include <iostream>
using namespace std;


int* read(int N);
int print(int* A, int N);
bool isInOrder(int*A, int N);

int main()
{
  char c;
  int N;
  cin >> c >> c >> N;

  int* A = read(N);
  print(A,N);
  if (isInOrder(A,N))
    cout << "Is in order!" << endl;
  else
    cout << "Is not in order!" << endl;
  delete [] A;
  return 0;
}

int* read(int N){

  int* A = new int[N];
  char junk;
  cin >> junk;
  int x;

  for (int i = 0; i < N; i++){
    cin >> x;
    A[i] = x;
  }

  return A;
}

int print(int* A, int N){
  char x = 'A'-1;
  for (int i = 0; i < N; i++){
    cout << " " << A[i];
  }
  cout << endl;
  for (int i = 0; i < 2*N+1; i++){
    cout << "-";
  }
  cout << endl;
  for (int i = 0; i < N; i++){
    x++;
    cout << " " << x;
  }
  cout << endl;
  return 1;
}

bool isInOrder(int* A, int N){
  for (int i = 0; i < N-1; i++){
    if (A[i] > A[i+1]){
      return false;
    }
  }
  return true;
}
