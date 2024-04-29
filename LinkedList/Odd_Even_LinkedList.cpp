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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* temp = head;
        ListNode* original_even = head->next;
        ListNode* even = head->next;
        ListNode* forward = head;
        while( temp->next!=nullptr && even->next!=nullptr){
          forward = temp->next->next;
          even = temp->next;
          temp->next = temp->next->next;
          even->next = even->next->next;
          temp = forward;
          even = forward->next;
         
        }
        temp->next = original_even;
        
        return head;
        
    }
};