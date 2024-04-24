#pragma once
#include <iostream>
using namespace std;

struct Pair
{
  string word;
  int x;
};
istream& operator >> (istream& is, Pair& p);
ostream& operator << (ostream& os, Pair p);
