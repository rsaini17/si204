#include <iostream>
using namespace std;
#pragma once
struct point
{
  double x, y;
};
istream& operator >> (istream& in, point& p);
ostream& operator << (ostream& os, point p);
