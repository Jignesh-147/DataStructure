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
       
       ListNode* curr = head;
       ListNode* prev = NULL;
       ListNode* forward = NULL;
       while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1->next == NULL && l2->next == NULL){
            int sum  = l1->val + l2 ->val;
            if(sum>9){
                l1->val = sum/10;
                ListNode* temp = new ListNode(sum%10);
                l1->next = temp;
            }
            else{
                l1->val = sum;
            }
            return l1;
        }
        
        ListNode* temp1 = reverser(l1);
        l1 = temp1;
        ListNode* temp2 = reverser(l2);
        int sum = 0;
        int carry = 0;
        int count = 0;
        while(temp1!=NULL && temp2!=NULL){
            sum = temp1->val + temp2->val + carry;
            temp1->val = sum%10;
            carry = sum/10;
            if(temp1 -> next == NULL && temp2 -> next != NULL){
                temp1->next = temp2->next;
                temp1 = temp1->next;
                break;
            }
            if(temp1->next == NULL && temp2->next == NULL){
                count=1;
                break;
            }
            temp1 = temp1 -> next;
            temp2 = temp2->next;
        }
        while(temp1!=NULL && count==0){
             sum = temp1->val + carry;
             temp1->val = sum%10;
             carry = sum/10;
             if(temp1->next == NULL){
                break;
             }
             temp1 = temp1->next;
        }
        if(carry!=0){
            ListNode* temp = new ListNode(carry);
            temp1->next = temp;
        }
        ListNode* result = reverser(l1);
        return result;



    }
};