/*Author: MIDN Ronny Saini
 *Filename: p2.cpp
 *Swap it
 */

#include <iostream>
using namespace std;


int* read(int N);
int print(int* A, int N);
bool isInOrder(int*A, int N);
int* swap(int* A, char x, char y);
/*Author: MIDN Ronny Saini
 *Filename: p1.cpp
 *Array Functions
 */

#include <iostream>
using namespace std;


int* read(int N);
int print(int* A, int N);
bool isInOrder(int*A, int N);
int* swap(int* A, char x, char y);

int main()
{
  cout << "Welcome to SWARE!" << endl << "board> ";
  char c;
  int N;
  cin >> c >> c >> N;

  int* A = read(N);
  cout << endl << endl;
  print(A,N);

  string z;
  char x,y;
  int count = 0;
  while (!isInOrder(A,N)){
    cout << "> ";
    cin >> z; 
    if (z == "swap"){
      cin >> x >> y;
      A = swap(A, x, y);
      cout << endl << endl;
      print(A, N);
      count++;
    } else {
      cout << "Unknown move '" << z << "'" << endl << endl;
      print (A, N);
    }
  }
  
  cout << count*3 << " points! (" << count << " moves)" << endl;
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

int* swap(int* A, char x, char y){
  int a = x-'A';
  int b = y-'A';
  int temp = A[a];
  A[a] = A[b];
  A[b] = temp;

  return A;
}
