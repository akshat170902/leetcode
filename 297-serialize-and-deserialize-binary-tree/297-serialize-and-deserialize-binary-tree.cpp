/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="|";
        queue<TreeNode*>q;
        if(root){
            s+=to_string(root->val)+"|";
            q.push(root);
        }
        else{
            s+="n|";
        }
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*p=q.front();
                q.pop();
                
                if(p->left){
                    q.push(p->left);
                    s+=to_string(p->left->val)+"|";
                }
                else{
                    s+="n|";
                }
                if(p->right){
                    q.push(p->right);
                    s+=to_string(p->right->val)+"|";
                }
                else{
                    s+="n|";
                }
            }
        }
        cout<<s<<endl;
        return s;
    }

    int valFinder(string s,int &i){
        i++;
        if(i<s.size()&&s[i]=='n'){
            i++;
            return -10000;
        }
        int neg=1;
        if(s[i]=='-'){
            neg=-1;
            i++;
        }
        int val=0;
        while(i<s.size()&&s[i]!='|'){
            val=val*10+s[i]-'0';
            i++;
        }
        return neg*val;
    }
    TreeNode* nodeCreate(int val){
        if(val==-10000){
            return nullptr;
        }
        
        return new TreeNode(val);
        
    }
    TreeNode* deserialize(string s) {
        
        queue<TreeNode*>q;
        int i=0;
        int val=valFinder(s,i);
        TreeNode*root=nodeCreate(val);
        if(root){
            q.push(root);
        }
        while(!q.empty()){
            TreeNode*cur=q.front();
            q.pop();
            cur->left=nodeCreate(valFinder(s,i));
            cur->right=nodeCreate(valFinder(s,i));
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));