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
    Node* copyRandomList(Node* head) {
        
        if(head==nullptr)return nullptr;
        unordered_map<Node*,Node*>m;
        Node*h=head;
        Node*r=new Node(head->val);
        m[head]=r;
        Node*p=r;
        head=head->next;
        while(head){
                Node*temp=new Node(head->val);
                r->next=temp;
               r=temp;
            
            m[head]=r;
            head=head->next;
        }
        r=p;
        head=h;
        while(head){
            if(head->random==nullptr){
                r->random=nullptr;
            }
            else{
                r->random=m[head->random];
            }
            head=head->next;
            r=r->next;
        }
        return p;
    }
};