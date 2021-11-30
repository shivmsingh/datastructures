#include <iostream>
#include "linkedlist.h"
using namespace std;

Node *recreversell(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    
    Node* shead = recreversell(head->next);
    head->next->next = head;
    head->next = nullptr;
    
    return shead;
}

int main(){
    Node* head = buildll();
    printll(head);
    head = recreversell(head);
    printll(head);
}
