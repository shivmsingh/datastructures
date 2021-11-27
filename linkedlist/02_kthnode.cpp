#include <iostream>
#include "linkedlist.h"
using namespace std;

int kthnode(Node *head, int pos) {
  Node *fast = head;
  Node *slow = head;

  while (pos > 0) {
    fast = fast->next;
    pos--;
  }
  while (fast != nullptr) {
    slow = slow->next;
    fast = fast->next;
  }

  return slow->data;
}

int main() {
  Node*head = buildll();
  printll(head);
  cout<<kthnode(head,4)<<'\n';
}
