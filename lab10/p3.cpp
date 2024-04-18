#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "easycurses.h"
using namespace std;

struct letter {
  char l;
  int x, y;
};

void inputLetter(letter &l){
  char junk;
  cin >> l.l >> junk >> l.x >> junk >> l.y >> junk;
}

int main() {
  int numLetters;
  cin >> numLetters;
  letter* letters = new letter[numLetters];
  for (int i = 0; i < numLetters; i++){
    inputLetter(letters[i]);
  }

  startCurses();

  for (int i = 0; i < numLetters; i++){
    drawCharAndRefresh(letters[i].l, letters[i].x, letters[i].y);
    usleep(800000);
  }

  for (int i = 0; i < numLetters; i++){
    drawChar(' ', letters[i].x, letters[i].y);
  }
  refreshWindow();
  usleep(800000);

  char c;

  c = inputChar();
  if (c == 'q') {
    endCurses();
  }
  else {
    for (int i = 0; i < numLetters; i++){
      drawCharAndRefresh(letters[i].l, letters[i].x, letters[i].y);
      usleep(800000);
    }

    for (int i = 0; i < numLetters; i++){
      drawChar(' ', letters[i].x, letters[i].y);
    }
    refreshWindow();
    usleep(800000);
  }

  endCurses();

  delete [] letters;

  return 0;
}

