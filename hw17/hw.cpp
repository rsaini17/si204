/*Author: MIDN Ronny Saini
 *Filename: hw.cpp
 *String Reverser
*/

#include <iostream>
using namespace std;

int main(){

  int words = 0;
  cout << "Number of words: ";
  cin >> words;

  string sentence;
  cout << "Sentence: ";

  string* S = new string[words];

  for (int i = 0; i < words; i++){
    cin >> S[i];
  }

  for (int i = 0; i < words -1; i++){
    cout << S[i] << " ";
  }
  cout << S[words-1] << "?";

  for (int i = words; i > 0; i--){
    cout << S[i] << " ";
  }
  cout << S[0] << "!" << endl;

}

