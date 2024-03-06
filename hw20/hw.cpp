/*Author: MIDN Ronny Saini
 *Filename: hw.cpp
 *Flight Tracker
 */

#include <iostream>
using namespace std;


int main(){
  
  int legs;
  string s; 
  
  cout << "How many legs? ";
  cin >> legs;
  string* reverse = new string[legs]; 
  string* airports = new string[2];

  for(int i = 0; i < legs; i++){
     cin >> s;
     string airport1, airport2;
     for (int j = 0; j < 3; j++){
       airport1 += s[j];
       cout << "a1: " << airport1 << endl;
     }
     for (int z = s.length()-3; z < s.length(); z++){
       airport2 += s[z];
       cout << "a2: " << airport2 << endl;
     }
     if(i == 0){
       airports[0] = airport1;
       airports[1] = airport2;
     } else {
        if (airports[1] != airport1){
          cout << "city mismatch" << endl;
          return -1;
        } else {
          airports[0] = airport1;
          airports[1] = airport2;
        }
     }
     reverse[i] = airport2 + "->" + airport1;
  }
 
  cout << "Reverse trip: ";

  for(int i = 0; i <= legs; i++){
    if(i == legs){
      cout << reverse[i] << endl;
    } else {
      cout << reverse[i] << "->";
    }
  }

  delete[] reverse;
  delete[] airports;

  return 0;
}


