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
    ListNode* reverser(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* forward = nullptr;
        while(curr!=nullptr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        slow = reverser(slow->next);
        fast = head;

        while(fast!=nullptr && slow!=nullptr){
            if(fast->val!=slow->val){
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return true;

        
    }
};