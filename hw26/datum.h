#pragma once
#include "point.h"
#include "hhmmss.h"
#include <iostream>
using namespace std;

struct datum
{
  point position;
  hhmmss time;
};
istream& operator >> (istream& is, datum& D);
