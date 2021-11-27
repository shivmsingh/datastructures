#include <iostream>
#include "linkedlist.h"
using namespace std;

void reversell(Node *&head) {
  Node *fwd = head;
  Node *curr = head;
  Node *prev = nullptr;

  while (curr) {
    fwd = curr->next;
    curr->next = prev;
    prev = curr;
    curr = fwd;
  }

  head = prev;
}

int main() {
  Node*head = buildll();
  printll(head);
  reversell(head);
  printll(head);
}
