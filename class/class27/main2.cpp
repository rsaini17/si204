#include <iostream>
using namespace std;
#include "point.h"     // NOTE HERE
#include "vec.h"      // NOTE HERE

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
