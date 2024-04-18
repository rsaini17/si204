#include "Pos.h"
#include <iostream>
#include <fstream>
#pragma once

struct Board {
  char** grid;
  int rows;
  int cols;
  Pos playerStart;
  Pos goal;
  Pos* spawns;
  int numSpawns;
};

Board createBoard();
void destroyBoard(Board& board);
bool readBoard(Board& board, const char* filename);
void printBoard(const Board& board);
void printStartAndSpawns(const Board& board);
