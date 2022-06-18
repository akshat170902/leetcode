/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* helper(Node*head){
        Node*prevm=head;
        while(head){while(head&&head->child==nullptr){
            prevm=head;
            head=head->next;
        }
        if(head){Node*p=head->next;
        Node*chld=head->child;
                 
        Node*child=helper(chld);
                 head->child=nullptr;
        head->next=chld;
        chld->prev=head;
                 head=p;
                 prevm=child;
        if(p){child->next=p;
        p->prev=child;}}}
        return prevm;
        
    }
    Node* flatten(Node* head) {
        helper(head);
        return head;
  }
};