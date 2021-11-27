#include <iostream>
#include "linkedlist.h"
using namespace std;

int midpoint(Node *head) {
  Node *fast = head->next;
  Node *slow = head;

  while (fast != nullptr and fast->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
  }

  return slow->data;
}

int main() {
  Node*head = buildll();
  printll(head);
  cout<<midpoint(head)<<'\n';
}
