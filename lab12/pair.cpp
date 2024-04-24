#include <iostream>
using namespace std;
#include "pair.h"

istream& operator >> (istream& is, Pair& p)
{
  char c;
  return is >> c >> p.word >> p.x >> c;
}

ostream& operator << (ostream& os, Pair p)
{
  return os << '(' << p.word << ' ' << p.x << ')';
}

