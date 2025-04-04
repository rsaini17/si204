/*Author: MIDN Ronny Saini
 *Filename: part1.cpp
 *Bounding box
 */

#include <iostream>
using namespace std;

int main(){

  //declare variables
  char a,b,c,d,e,f,g,h;
  double x1,y1,x2,y2,x3,y3, xmin, xmax, ymin, ymax;

  //user input
  cin >> a >> x1 >> b >> y1 >> c >> d >> x2 >> e >> y2 >> f >> g >> x3 >> h >> y3;

  //go through all the points to find the x min, x max, y min, y max;
  xmin = x1;
  if (x2 < x1){
    xmin = x2;
  }
  if (x3 < x2 && x3 < x1){
    xmin = x3;
  }

  xmax = x1;
  if (x2 > x1){
    xmax = x2;
  }
  if (x3 > x1 && x3 > x2){
    xmax = x3;
  }
  
  ymin = y1;
  if (y2 < y1){
    ymin = y2;
  }
  if (y3 < y2 && y3 < y1){
    ymin = y3;
  }

  ymax = y1;
  if (y2 > y1){
    ymax = y2;
  }
  if (y3 > y1 && y3 > y2){
    xmax = x3;
  }

  //print the rectangle border
  cout << xmin << " " << ymin << endl << xmin << " " << ymax << endl << xmax << " " << ymax << endl << xmax << " " << ymin << endl << xmin << " " << ymin << endl << endl;

  //print triangle back out
  cout << x1 << " " << y1 << endl << x2 << " " << y2 << endl << x3 << " " << y3 << endl << x1 << " " << y1 << endl;

  return 0;
}

