/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        
        
        while(l1 or l2){
            int sum = carry;
            
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            
            if(sum >= 10){
                sum = sum - 10;
                carry = 1;
            }else{
                carry = 0;
            }
            ListNode* temp = new ListNode(sum);
            if(head == nullptr){
                head = temp;
            }
            if(tail) tail->next = temp;
            tail = temp;
            
        }
        if(carry > 0){
            ListNode* temp = new ListNode(carry);
            tail->next = temp;
            return head;
        }
        return head;
    }
};