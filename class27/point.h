#pragma once     // **** NOTE HERE
#include <iostream>
using namespace std;

/*********************************************
* * PROTOTYPES & STRUCT DEFINITIONS
* ********************************************/
struct point
{
  double x, y;
};
istream& operator >> (istream& is, point& p);
ostream& operator << (ostream& os, point p);
point operator + (point a, point b);
point operator / (point p, double z);
