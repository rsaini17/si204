/*Author: MIDN Ronny Saini
 *Filename: hw.cpp
 *Leap Year Checker
 */

#include <iostream> 
using namespace std;

int main(){
  
  //declare variables
  int year;
  bool leapyear;
  
  //user input
  cout << "Enter year: ";
  cin >> year;

  //check
  if (year%4 == 0){
    if (year%100 == 0){
      if (year%400 == 0){
        leapyear = 1;
      } else {
        leapyear = 0;
      } 
    } else { 
      leapyear = 1;
    }
  } else {
    leapyear = 0;
  }


  //print statement
  if (leapyear == 1){
    cout << "Is Leap Year" << endl;
  } else {
    cout << "Is Not Leap Year" << endl;
    }

  return 0;
}
