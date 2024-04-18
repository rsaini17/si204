/*Author: MIDN Ronny Saini
 *Filename: hw.cpp
 *print out words reverse by first letter
*/

#include <iostream>
using namespace std;

struct Node {
    string word;
    Node* next;
};

Node* add2front(string val, Node* oldlist);
void deletelist(Node* L);
void print(Node* L, char letter); 

int main(){
  Node* LIST = 0; 
  cout << "Enter words followed by END:" << endl;
  string x;
  while(cin >> x && x != "END")
    LIST = add2front(x,LIST);

  cout << "What letter? ";
  char y;
  cin >> y;

  print(LIST, y);
  deletelist(LIST);
}

Node* add2front(string val, Node* oldlist){
  Node* temp = new Node;
  temp->word = val;
  temp->next = oldlist;
  return temp;				
}

void deletelist(Node* L){
  if (L == NULL)
    return;
  deletelist(L->next);
  delete L;               
}

void print(Node* L, char letter) {
    while (L != NULL) {
        if (L->word[0] == letter) {
            cout << L->word << endl;
        }
        L = L->next;
    }
}


