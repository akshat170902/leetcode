/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*,Node*>m;
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        if(m.count(node)==0){
            Node*clone=new Node(node->val);
            m[node]=clone;
            for(auto child:node->neighbors){
                clone->neighbors.push_back(cloneGraph(child));
            }
        }
        return m[node];
    }
};