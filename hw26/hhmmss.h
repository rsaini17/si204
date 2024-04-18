#include <iostream>
using namespace std;
#pragma once
struct hhmmss
{
  int h,m,s;
};
istream& operator >> (istream& is, hhmmss& T);
bool operator < (hhmmss a, hhmmss b);


