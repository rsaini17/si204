/*Author: MIDN Ronny Saini
 *Filename: p5.cpp
 *Pretty Print 
 */

#include <iostream>
using namespace std;

int* makeDeck();
void printHand(int* hand, int* dealerHand, int size);
void shuffle(int* deck);
int max(int a, int b);

int main() {
    // Initialize deck
    int* deck = makeDeck();
    int deckIndex = 0;

    // Shuffle the deck
    char checkShuffle;
    cout << "Shuffle: [n | u <seed>]: ";
    cin >> checkShuffle;

    if (checkShuffle == 'u') {
      int seed;
      cin >> seed;
      srand(seed);
      shuffle(deck);
    } 

    // Initialize player and dealer hands
    int* playerHand = new int[25];
    int* dealerHand = new int [25];
    int playerIndex = 0;
    int dealerIndex = 0;

    // Deal initial cards to player and dealer
    for(int i = 0; i < 2; i++){
      playerHand[playerIndex] = deck[deckIndex];
      playerIndex++;
      deckIndex++;
      dealerHand[dealerIndex] = deck[deckIndex];
      dealerIndex++;
      deckIndex++;
    }

    //Show current hands
    cout << endl << "Player  Dealer" << endl;
    printHand(playerHand, dealerHand, playerIndex); // Player's hand

    // Game rounds
    for (int round = 1; round <= 3; round++) {
      cout << endl << "Round " << round << " Player's turn" << endl;
      cout << "hit or stand ? [h/s] ";
      char choice;
      cin >> choice;

      if (choice == 'h') {
        playerHand[playerIndex++] = deck[deckIndex++];
      }

      cout << endl << "Player  Dealer" << endl;
      printHand(playerHand, dealerHand, max(playerIndex, dealerIndex)); 
        
      cout << endl << "Round " << round << " Dealer's turn" << endl;
      cout << "hit or stand ? [h/s] ";
      cin >> choice;

      if (choice == 'h') {
        dealerHand[dealerIndex++] = deck[deckIndex++];
      }

      cout << endl << "Player  Dealer" << endl;
      printHand(playerHand, dealerHand, max(playerIndex, dealerIndex));
    }

    //delete arrays
    delete [] deck;
    delete [] playerHand;
    delete [] dealerHand;

    return 0;
}

int* makeDeck() {
    // Fill deck
    int* deck = new int[52];
    int index = 0;
    for (int suit = 1; suit <= 4; suit++) {
        for (int face = 2; face <= 14; face++) {
            deck[index++] = face + 100 * suit;
        }
    }
    return deck;
}

void printHand(int* playerHand, int* dealerHand, int size) {
    string suits[] = {"\u2663", "\u2666", "\u2665", "\u2660"};
    string faces[] = {"", "", "2", "3", "4", "5", "6", "7", "8", 
                      "9", "10", "J", "Q", "K", "A"};

    for (int i = 0; i < size; i++) {
        int card = playerHand[i];
        int suitValue = card / 100;
        int faceValue = card % 100;

        int card2 = dealerHand[i];
        int suitValue2 = card2 / 100;
        int faceValue2 = card2 % 100;

        cout << "|  ";
        if (faceValue == 0) {
            cout << "    |";
        } else if (faceValue == 10) {
            cout << faces[faceValue] << suits[suitValue - 1] << "  |";
        } else {
            cout << faces[faceValue] << suits[suitValue - 1] << "  |";
        }

        if (faceValue2 == 0) {
            cout << "      |";
        } else if (faceValue2 == 10) {
            cout << "  " << faces[faceValue2] << suits[suitValue2 - 1] << "  |";
        } else {
            cout << "  " << faces[faceValue2] << suits[suitValue2 - 1] << "  |";
        }
        cout << endl;
    }
}

void shuffle(int* deck) {
  for (int i = 0; i < 52; i++) {
    int j = rand() % 52;
    int temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

int max(int a, int b){
  if (a > b){
    return a;
  } else {
    return b;
  }
}
