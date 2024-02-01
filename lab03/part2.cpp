/*Author: MIDN Ronny Saini
 *Filename: part2.cpp
 *Classifying triangles
 */

#include <iostream>
using namespace std;

int main(){

  //declare variables
  double x,y,z;
  string length, angle;

  //user input
  cout << "Enter side lengths: ";
  cin >> x >> y >> z;

  //put side lengths into increasing length order
  if (x > z){
    double holder = z;
    z = x;
    x = holder;
  }
  if (y > z){
    double holder = z;
    z = y;
    y = holder;
  }


  //check to make sure its a triangle 
  if (x+y <= z){
    cout << "Error! these lengths violate the triangle inequality!" << endl;
    return 0;
  }

  //decribe side lengths
  if (x == y && x == z){
    length = "equilateral";
  } else if (x == y || x == z || y == z){
    length = "isosceles";
  } else {
    length = "scalene";
  }

  //describe interior angles
    int sum = x*x + y*y;
  if (sum == z*z){
    angle = "right";
  } else if (sum > z*z){
    angle = "acute";
  } else {
    angle = "obtuse";
  }

  //print to user 
  cout << "This is a " << angle << " " << length << " triangle." << endl;

  return 0;
}
