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
    void deleter(ListNode* head,int &val,ListNode* &forward,ListNode* &prev){
        if(head==NULL){
            return ;
        }
        if(head->val==val){
            forward=head->next;
            prev->next=forward;
            delete head;
            head=forward;
        }
        deleter(head,val,forward,prev);
    }
    ListNode* removeElements(ListNode* head, int val) {
        while(head->val==val){
            ListNode* temp=head->next;
            delete head;
            head=temp;
        }
        ListNode* prev=head;
        ListNode* forward=NULL;
        deleter(head,val,forward,prev);
        return head;
    }
};