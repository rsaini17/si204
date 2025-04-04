#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double x, y, z;
  cout << "Enter length x: ";
  cin >> x;
  cout << "Enter length y (<" << x << "): ";
  cin >> y;
  double ac = sqrt(x*x-y*y);
  cout << "Enter length z (<" << ac << "): ";
  cin >> z;

  double dc = ac - z;
  double bd = sqrt((dc*dc)+(y*y));

  cout << "Length of BD is " << bd <<endl;

  return 0;
}
