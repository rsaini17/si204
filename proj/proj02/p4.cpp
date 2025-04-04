/*Author: MIDN Ronny Saini
 *Filename: p4.cpp
 *Shuffle Deck 
 */

#include <iostream>
using namespace std;

int* makeDeck();
void printHand(int* hand, int size);
void shuffle(int* deck);

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

    //print deck
    cout << "[";
    for (int i = 0; i < 51; i++) {
      cout << deck[i] << " ";
    }
    cout << deck[51] << "]" << endl << endl;


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
    cout << endl << "Player: ";
    printHand(playerHand, playerIndex);
    cout << "Dealer: ";
    printHand(dealerHand, dealerIndex);

    // Game rounds
    for (int round = 1; round <= 3; round++) {
        cout << endl << "Round " << round << " Player's turn" << endl;
        cout << "hit or stand ? [h/s] ";
        char choice;
        cin >> choice;

        if (choice == 'h') {
            playerHand[playerIndex++] = deck[deckIndex++];
        }

        cout << endl << "Player: ";
        printHand(playerHand, playerIndex);
        cout << "Dealer: ";
        printHand(dealerHand, dealerIndex);

        cout << endl << "Round " << round << " Dealer's turn" << endl;
        cout << "hit or stand ? [h/s] ";
        cin >> choice;

        if (choice == 'h') {
            dealerHand[dealerIndex++] = deck[deckIndex++];
        }

        cout << endl << "Player: ";
        printHand(playerHand, playerIndex);
        cout << "Dealer: ";
        printHand(dealerHand, dealerIndex);
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

void printHand(int* hand, int size) {
    cout << "[";
    for (int i = 0; i < size - 1; i++) {
        cout << hand[i] << " ";
    }
    if (size > 0) {
        cout << hand[size - 1];
    }
    cout << "]" << endl;
}

void shuffle(int* deck) {
  for (int i = 0; i < 52; i++) {
    int j = rand() % 52;
    int temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

