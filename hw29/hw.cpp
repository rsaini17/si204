/*Author: MIDN Ronny Saini
 *Filename: hw.cpp
 *third to last reverse order
 */

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

Node* add2front(int val, Node* LIST);

int main()
{
  Node* LIST = 0; 

  int x;
  while(cin >> x && x > 0)
    LIST = add2front(x,LIST);

  cout << LIST->next->next->data << endl;

  return 0;
}

Node* add2front(int val, Node* LIST)
{
  Node* temp = new Node;
  temp->data = val;
  temp->next = LIST;
  return temp;
}
