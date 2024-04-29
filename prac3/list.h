/******************************************
list.h

DO NOT DELETE ANY CODE BELOW
Only add code below as necessary
******************************************/

#pragma once
#include <iostream>
using namespace std;

struct Character
{
  char label;
  int row, col;
};

ostream& operator << (ostream& os, Character c);

struct Node
{
  Character data;
  Node* next;
};

Node* add2back(Character c, Node* L);
void print(Node* L);
void nodesLeftOf(Node* L, int col);
void removeThird(Node* L);
void deletelist(Node* L);

