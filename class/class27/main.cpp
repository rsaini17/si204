#include <iostream>
using namespace std;
#include "point.h"    // NOTE 1

struct Vector
{
  char label;
  point s, t;
};

int main()
{
  // Create a vector V
  Vector V;

  // Read label and vertices
  cout << "Enter label and 2 vertices: ";
  cin >> V.label >> V.s >> V.t;

  // Write label and vertices
  cout << "Your vector is " << V.label << " "
       << V.s << " " << V.t << endl;

  return 0;
}
