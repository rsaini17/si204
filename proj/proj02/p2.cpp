/*Author: MIDN Ronny Saini
 *Filename: p2.cpp
 *Dealing cards to Player and Dealer
 */

#include <iostream>
using namespace std;

int* makeDeck();
void printHand(int* hand, int size);

int main() {
    // Initialize deck
    int* deck = makeDeck();
    int deckIndex = 0;
    
    //print deck
    cout << "[";
    for (int i = 0; i < 51; i++) {
      cout << deck[i] << " ";
    }
    cout << deck[51] << "]" << endl;


    // Initialize player and dealer hands
    int* playerHand = new int[25];
    int* dealerHand = new int [25];
    int playerIndex = 0;
    int dealerIndex = 0;

    //get user inputs and deal
    string command;
    while (true) {
        cout << "> ";
        cin >> command;
        if (command == "print-p") {
            printHand(playerHand, playerIndex);
        } else if (command == "print-d") {
            printHand(dealerHand, dealerIndex);
        } else if (command == "deal-p") {
            playerHand[playerIndex] = deck[deckIndex];
            playerIndex++;
            deckIndex++;
        } else if (command == "deal-d") {
            dealerHand[dealerIndex] = deck[deckIndex];
            dealerIndex++;
            deckIndex++;
        } else if (command == "quit") {
            break;
        }
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
