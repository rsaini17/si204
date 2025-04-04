/*Author: MIDN Ronny Saini
 *Filename: p2.cpp
 *Problem 2 Prac
*/

#include <iostream>
using namespace std;

int main(){

  string s;
  while(cin >> s){
  
    if (s == "."){
      break; 
    } 
    else if (s.length() == 1){
    
    }
    else {
      bool x = false;
      char first = s[0];
      for (int i = 1; i < s.length(); i++){
        if (s[i] == first){
          s[i] = s[i]-32;
          x = true;
        }
      }
      if (x){
        s[0] = s[0]-32;
        cout << s << " ";
      }
    }
  }

  cout << endl;

  return 0;
}
