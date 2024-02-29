/*Author: MIDN Ronny Saini
 *Filename: p3.cpp
 *Reverse It!
 */

#include <iostream>
using namespace std;


int* read(int N);
int print(int* A, int N);
bool isInOrder(int*A, int N);
int* swap(int* A, char x, char y);
int* reverse(int* A, char x, char y);


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
  int count = 0, score = 0;
  while (!isInOrder(A,N)){
    cout << "> ";
    cin >> z; 
    if (z == "swap"){
      cin >> x >> y;
      A = swap(A, x, y);
      cout << endl << endl;
      print(A, N);
      count++;
      score = score + 3;
    } else if (z == "reverse") {
      cin >> x >> y;
      A = reverse(A,x,y);
      cout << endl << endl;
      print(A, N);
      count++;
      score = score + 2;
    } else {
      cout << "Unknown move '" << z << "'" << endl << endl;
      print (A, N);
    }
  }
  
  cout << score << " points! (" << count << " moves)" << endl;
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
  char x = 'A' - 1;
    int maxElement = findMax(A, N);
    for (int i = maxElement; i > 0; i--) {
        for (int j = 0; j < N; j++) {
            if (A[j] >= i) {
                cout << " #";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    } 
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

int* reverse(int* A, char x, char y){
  int a = x-'A';
  int b = y-'A';
  int size = b-a + 1;
  int* temp = new int[size];
  for (int i = 0; i < size; i++){
    temp[i] = A[b-i];
  }
  for (int i = 0; i < size; i++){
    A[a+i] = temp[i];
  }
  delete [] temp;
  return A;
}

int findMax(int* A, int N) {
    int max = A[0];
    for (int i = 1; i < N; ++i) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}
