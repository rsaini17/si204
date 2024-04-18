#include <iostream>
#include "datum.h"
#include "point.h"
#include "hhmmss.h"
using namespace std;

istream& operator >> (istream& is, datum& D)
{
  char c;
  return is >> c >> D.time >> c >> D.position >> c; 
}

