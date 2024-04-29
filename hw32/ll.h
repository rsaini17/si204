#pragma once
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* add2back(int data, Node* head);
void print(Node* head);
void enter_after(int newData, int target, Node* head);
Node* remove(int data, Node* head);
void deletelist(Node* head);
