/*Author: MIDN Ronny Saini
 *Filename: p1.cpp
 *Printin out a deck of cards
 */

#include <iostream>
using namespace std;

int* makeDeck();

int main(){
  
  
  //initialize deck
  int* deck = makeDeck(); 

  //print deck
  cout << "[";
  for (int i = 0; i < 51; i++) {
    cout << deck[i] << " ";
  }
  cout << deck[51] << "]" << endl;

  //delete array
  delete [] deck;
}

int* makeDeck(){
  //fill deck
  int* deck = new int[52];
  int i = 0;
  for (int suit = 1; suit <= 4; suit++) {
    for (int face = 2; face <= 14; face++) {
      deck[i++] = face + 100 * suit;
    }
  }
  return deck;
}
