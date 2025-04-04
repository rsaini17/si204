#pragma once
#include <iostream>
#include "point.h"
using namespace std;
struct hhmmss
{
  int h,m,s;
};
istream& operator >> (istream& is, hhmmss& T);
bool operator < (hhmmss a, hhmmss b);


