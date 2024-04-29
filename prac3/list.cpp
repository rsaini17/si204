/******************************************
list.cpp

DO NOT DELETE ANY CODE BELOW
Only add code below as necessary
******************************************/
#include <iostream>
#include "list.h"
using namespace std;

ostream& operator << (ostream& os, Character c)
{
  return os << "[" << c.label << " (" << c.row << "," << c.col << ")]";
}

Node* add2back(Character c, Node* L){
  if (L == NULL)
    return new Node{c, NULL};
  L->next = add2back(c, L->next);
  return L;
}


void print(Node* L) {
  if (L == NULL) {
    cout << endl;
  } else {
    cout << L->data << " ";
    print(L->next);
  }
}

void nodesLeftOf(Node* L, int col){
  if (L == NULL) {

  } else {
    if (L->data.col < col){
      cout << L->data << endl;
      nodesLeftOf(L->next, col);
    }
    else {
      nodesLeftOf(L->next, col);
    }
  }
}

void removeThird(Node* L){
  Node* temp = L->next->next; 
  L->next->next = temp->next;
  delete temp;
}

void deletelist(Node* L)
{
  if( L == NULL )
  {
    return;
  }
  else 
  {
    deletelist(L->next);
    delete L;
  }
}
