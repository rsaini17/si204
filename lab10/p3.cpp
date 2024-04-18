#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "easycurses.h"

using namespace std;

// Struct to represent a character with its position and direction
struct Letter {
    char l;
    int x, y;
    int directionY, directionX; // Direction of movement
};

// Function to input a character with its position
void inputLetter(Letter &l) {
    char junk;
    cin >> l.l >> junk >> l.x >> junk >> l.y >> junk;
    // Set initial direction to move right (east)
    l.directionY = 0;
    l.directionX = 1;
}

// Function to move a character one step based on its direction
void moveLetter(Letter &l) {
    l.x += l.directionY;
    l.y += l.directionX;
}

int main() {
    int numLetters;
    cin >> numLetters;
    Letter* letters = new Letter[numLetters];

    // Input characters
    for (int i = 0; i < numLetters; i++) {
        inputLetter(letters[i]);
    }

    startCurses();

    // Draw initial positions of characters
    for (int i = 0; i < numLetters; i++) {
        drawChar(letters[i].l, letters[i].x, letters[i].y);
    }
    refreshWindow();

    usleep(80000);

    // Animation loop
    for (int frame = 0; frame < 20; frame++) {
        // Move all characters one step
        for (int i = 0; i < numLetters; i++) {
            // Erase character from old position
            drawChar(' ', letters[i].x, letters[i].y);
            // Move character
            moveLetter(letters[i]);
            // Draw character in new position
            drawChar(letters[i].l, letters[i].x, letters[i].y);
        }

        refreshWindow();
        usleep(80000); // Sleep for 0.08 sec
    }

    endCurses();

    delete [] letters;

    return 0;
}
