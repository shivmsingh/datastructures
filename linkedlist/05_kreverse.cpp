#include <iostream>
#include "linkedlist.h"
using namespace std;

Node* kreverse(Node*& head, int k){
    if(head == nullptr) return nullptr;
    
    int p = k;
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = next;
    
    while(curr != nullptr and p > 0 ){
       next = curr -> next;
       curr -> next = prev;
       prev = curr;
       curr = next;
       p--;
    }
    
    if(curr != nullptr){
       head ->next = kreverse(next,k);
    }
    return prev;

}



int main(){
    Node* head = buildll();
    insertAtHead(head,7);
    insertAtHead(head,8);
    printll(head);
    head = kreverse(head,2);
    printll(head);
}
