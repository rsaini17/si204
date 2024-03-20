/*Author: MIDN Ronny Saini
 *Filename: stringGues.cpp
 *String Guess Name
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void printSpaced(string s);
string mkShadowString(string s);
string uncover(string original, string covered, char c);
string crossOut(char c, string s);

int main() {
    srand(time(0));

    //Get seed and word from user and file
    int seed;
    cout << "Welcome to String Guess!\nEnter a seed value: ";
    cin >> seed;
    srand(seed);
    ifstream file("words07.txt");
    int n = rand() % 1466;
    string chosenWord;
    for (int i = 0; i <= n; ++i) {
        file >> chosenWord;
    }

    //initialize variables
    int wrongGuesses = 8;
    string guessedLetters = "abcdefghijklmnopqrstuvwxyz";
    string coveredWord = mkShadowString(chosenWord);

    //play game
    while (wrongGuesses > 0 && coveredWord != chosenWord) {
        cout << "Wrong guesses remaining: " << wrongGuesses << "\t" 
          << guessedLetters << endl;
        printSpaced(coveredWord);
        cout << endl;

        char guess;
        cout << ": ";
        cin >> guess;

        if (chosenWord.find(guess) != string::npos) {
            coveredWord = uncover(chosenWord, coveredWord, guess);
            guessedLetters = crossOut(guess, guessedLetters);
        } else {
            cout << "There were no " << guess << "'s!" << endl;
            wrongGuesses--;
            guessedLetters = crossOut(guess, guessedLetters);
        }
    }

    if (coveredWord == chosenWord) {
        cout << "You win!!!! The word was " << chosenWord << endl;
    } else {
        cout << "You lose!!!! The word was " << chosenWord << endl;
    }

    return 0;
}

void printSpaced(string s){
  for(int i = 0; i < s.length(); i++){
    if(i == s.length()-1){
      cout << s[i];
    } else {
      cout << s[i] << " ";
    }
  }
}

string mkShadowString(string s){
  string ans;
  for(int i = 0; i < s.length(); i++){
    ans += "_";
  }
  return ans;
}

string uncover(string original, string covered, char c){
  string s;
  for (int i = 0; i < original.length(); i++){
    if (original[i] == c){
      s += c;
    } else {
      s += covered[i];
    }
  }
  return s;
}

string crossOut(char c, string s) {
  string ans;
  for (int i = 0; i < s.length(); i++){
    if(s[i] == c){
      ans += "*";
    } else {
    ans += s[i];
    }
  }
  return ans;
}
