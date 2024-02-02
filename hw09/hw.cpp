/*Author: MIDN Ronny Saini
 *Filename: hw.cpp
 *Cookie Counter
 */

#include <iostream>

using namespace std;

int main(){

  //declare variables
  int total = 0, total2 = 0, day = 0, max = 0, count = 0;

  //get total from user
  cout << "How many cookies? ";
  cin >> total;

  //while loop to get cookies per day
  while (total > 0){
    count++;
    cout << "Cookies eaten on day " << count << ": ";
    cin >> day;
    if (day > total){
      cout << "Not enough cookies!" << endl;
      return 1;
    }
    if (day > max){
      max = day;
    }
    total = total - day;
    total2 = total2 + day;
  }
  
  //print to user
  cout << "You ate " << total2 << " cookies over " << count << " days." << endl << "On your piggiest day you ate " << max << " cookies." << endl;

  return 0;
}
