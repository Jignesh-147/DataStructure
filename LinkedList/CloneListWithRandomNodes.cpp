/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insert_at_tail(Node* &clone_head, Node* &clone_tail, int data){
        Node* new_node = new Node(data);
        if(clone_head==NULL){
            clone_head=new_node;
            clone_tail=new_node;
        }
        else{
            clone_tail->next=new_node;
            clone_tail=new_node;
        }
        return ;
    }
    Node* copyRandomList(Node* head) {
        Node* clone_head=NULL;
        Node* clone_tail=NULL;

        Node* temp=head;
        while(temp!=NULL){
            insert_at_tail(clone_head,clone_tail,temp->val);
            temp=temp->next;
        }
        //mapping here
        unordered_map<Node* , Node*> old_new;
        Node* original_node=head;
        Node* clone_node=clone_head;


        while(original_node!=NULL && clone_node!=NULL){
            old_new[original_node]=clone_node;
            original_node=original_node->next;
            clone_node=clone_node->next;
        }
        temp=head;
        while(temp!=NULL){
           old_new[temp]->random=old_new[temp->random];
           temp=temp->next;
        }
        return clone_head;

    }
};