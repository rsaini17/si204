/*Author: MIDN Ronny Saini
 *Filename: part3.cpp
 *Pretty print
 */

#include <iostream>
#include <fstream>
using namespace std;
#include "pair.h"

struct Node
{
  Pair data;
  Node* next;
};

Node* add2front(Pair val, Node* oldlist);
Node* add2back(Pair d, Node* L);
void printlist(Node* L);
void printlist2(Node* L);
int score(Node* L);
void deletelist(Node* L);

int main(){

  Node* LIST = 0;
  cout << "Input file is: ";
  string filename = " ";
  cin >> filename;
  ifstream fin(filename);

  if(!fin){
    cout << "Error! File '" << filename << "' not found!" << endl;
  }

  int count = 0;
  Pair temp;
  while (fin >> temp){
    LIST = add2front(temp, LIST);
    count++;
  }

  Node* copy = 0;
  Node* tempp = LIST;
  char ans = ' ';
  while(tempp != NULL){
    cout << endl << "The current node: " << tempp->data << endl;
    cout << "Nodes before the current: ";
    printlist(copy);
    copy = add2back(tempp->data, copy);
    count--;
    cout << endl << "#nodes after the current: " << count << endl;
    cout << "[a]ccept or [r]eject: ";
    cin >> ans;
    tempp = tempp->next;
    cout << endl;
  }

  int total = score(LIST);
  cout << "List is: ";
  printlist2(LIST);
  cout << endl << "Score is: " << total << endl;
  
  deletelist(copy);
  deletelist(LIST);

  return 0;
}

Node* add2front(Pair val, Node* oldlist)
{
  Node* temp = new Node;
  temp->data = val;
  temp->next = oldlist;
  return temp;				
}

Node* add2back(Pair val, Node* L)
{
  if (L == NULL)
    return new Node{val, NULL};
  L->next = add2back(val, L->next);
  return L;
}

void printlist(Node* L) {
  if (L == NULL) {
  } else {
    cout << L->data << " ";
    printlist(L->next);
  }
}

void printlist2(Node* L) {
  if (L == NULL) {
  } else {
    cout << L->data.word << " ";
    printlist2(L->next);
  }
}

int score(Node* L){
 if(L == NULL){
   return 0;
 } else {
   return L->data.x + score(L->next);
 }
}


void deletelist(Node* L)
{
  if (L == NULL)
    return;

  deletelist(L->next);
  delete L;               
}


