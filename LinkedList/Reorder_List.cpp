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
    //divide linked list into two
    ListNode* break_into_two(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next;
        slow->next = nullptr;
        return temp;

    }
void reorderList(ListNode* head) {
      ios_base::sync_with_stdio(0);
    if (!head || !head->next) return;

    // Break the linked list into two halves
    ListNode* second_part = break_into_two(head);

    // Push the second half nodes into the stack
    stack<ListNode*> nodesStack;
    while (second_part != nullptr) {
        nodesStack.push(second_part);
        second_part = second_part->next;
    }

    // Reorder the list by alternating nodes from the first and second halves
    ListNode* temp = head;
    while (!nodesStack.empty()) {
        ListNode* top = nodesStack.top();
        nodesStack.pop();
        ListNode* next = temp->next;
        temp->next = top;
        top->next = next;
        temp = next;
    }

    // Ensure the last node points to nullptr to end the list
    if (temp != nullptr) temp->next = nullptr;
}
};