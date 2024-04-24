/*Author: MIDN Ronny Saini
 *Filename: part1.cpp
 *Printing and Counting
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
void deletelist(Node* L);

int main(){

  Node* LIST = 0;
  cout << "Input file is: ";
  string filename = " ";
  cin >> filename;
  ifstream fin(filename);

  if(!fin){
    cout << "Error! File '" << filename << "' not found!" << endl;
    return -1;
  }

  int count = 0;
  Pair temp;
  while (fin >> temp){
    LIST = add2front(temp, LIST);
    count++;
  }

  cout << "Count is " << count << endl;

  Node* tempp = LIST;
  while(tempp != NULL){
    cout << tempp->data << " ";
    tempp = tempp->next;
  }
  cout << endl;

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

void deletelist(Node* L)
{
  if (L == NULL)
    return;

  deletelist(L->next);
  delete L;               
}
