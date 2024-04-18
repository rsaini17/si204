#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include "easycurses.h"

using namespace std;

struct Letter {
    char l;
    int x, y;
    int directionX, directionY;
};

void inputLetter(Letter &l);
void moveLetter(Letter &l, int windowHeight, int windowWidth);
void changeDirection(Letter &l);


int main() {
    int numLetters;
    cin >> numLetters;
    Letter* letters = new Letter[numLetters];

    srand(time(0));

    for (int i = 0; i < numLetters; i++) {
        inputLetter(letters[i]);
    }

    startCurses();

    int windowHeight, windowWidth;
    getWindowDimensions(windowHeight, windowWidth);

    for (int i = 0; i < numLetters; i++) {
        drawChar(letters[i].l, letters[i].x, letters[i].y);
    }
    refreshWindow();

    usleep(80000);

    char c = ' ';
    while (c != 'q') {
        for (int i = 0; i < numLetters; i++) {
            drawChar(' ', letters[i].x, letters[i].y);
            changeDirection(letters[i]);
            moveLetter(letters[i], windowHeight, windowWidth);
            drawChar(letters[i].l, letters[i].x, letters[i].y);
        }

        refreshWindow();
        usleep(80000);

        c = inputChar();    
    }

    endCurses();

    delete [] letters;

    return 0;
}

void inputLetter(Letter &l) {
    char junk;
    cin >> l.l >> junk >> l.x >> junk >> l.y >> junk;
    l.directionX = 1;
    l.directionY = 0;
}

void moveLetter(Letter &l, int windowHeight, int windowWidth) {
    l.x += l.directionX;
    l.y += l.directionY;

    if (l.x < 0 || l.x >= windowHeight || l.y < 0 || l.y >= windowWidth) {
        l.directionX = -l.directionX;
        l.directionY = -l.directionY;
    }
}

void changeDirection(Letter &l) {
    if (rand() % 5 == 0) {
        int r = rand() % 2;
        if (l.directionX != 0) {
            l.directionX = 0;
            l.directionY = (r == 0) ? 1 : -1;
        } else {
            l.directionY = 0;
            l.directionX = (r == 0) ? 1 : -1;
        }
    }
}


