/************************************************
  p1.cpp

  DO NOT DELETE ANY CODE BELOW. 
  Only add code as necessary.
 *************************************************/

#include <iostream>
using namespace std;

struct position
{
  int row, col;
};

struct movement
{
  char dir;
  int length;
};

istream& operator >> (istream& is, position& p);
istream& operator >> (istream& is, movement& m);

ostream& operator << (ostream& os, position p);

position operator + (position p, movement m);

int main()
{
  position p; 
  cout << "position? ";
  cin >> p;

  cout << "how many moves? ";
  int n; 
  cin >> n;

  for(int i=0; i<n; i++)
  {
    movement v;
    cin >> v;
    p = p + v;
    cout << p << endl;
  }

  return 0;
}

istream& operator >> (istream& is, position& p)
{
  char c;
  return is >> c >> p.row >> c >> p.col >> c;
}

istream& operator >> (istream& is, movement& m)
{
  return is >> m.dir >> m.length;
}


ostream& operator << (ostream& os, position p)
{
  return os << "(" << p.row << "," << p.col << ")";
}

position operator + (position p, movement m)
{
  position r = {p.row, p.col};
  
  if (m.dir == 'N')
    r.row = r.row - m.length;
  else if (m.dir == 'S')
    r.row = r.row + m.length;
  else if (m.dir == 'E')
    r.col = r.col + m.length;
  else if (m.dir == 'W')
    r.col = r.col - m.length;

  return r;
}
