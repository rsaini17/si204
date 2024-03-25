/*Author: MIDN Ronny Saini
 *Filename: hw.cpp
 *Cars
*/

#include <iostream>
#include <fstream>
using namespace std;

struct Car {
    char tag;
    double pos;
    double vel;
};

int main() {
  string filename;
  cin >> filename;

  ifstream fin(filename);

  string junk;
  int num;

  fin >> junk >> junk >> num;

  Car* A = new Car[num];

  for (int i = 0; i < num; i++) {
    fin >> A[i].tag >> junk >> A[i].pos >> junk >>
      A[i].vel;
  }

  for (int hour = 0; hour <= 8; hour++) {
    cout << "hour " << hour << " ";
      for (int i = 0; i < num; i++) {
        double location = A[i].pos + hour * A[i].vel;
        cout << "[" << A[i].tag << ":" << location << "]";
      }
    cout << endl;
  }
  
  delete [] A;

  return 0;
}
