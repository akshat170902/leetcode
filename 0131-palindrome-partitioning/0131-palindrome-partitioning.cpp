class Solution {
public:
    bool isPalindrome(int &left,int &len,string &s){
        if(len==1){
            return true;
        }
        int right=left+len-1;
        for(int i=0;i<=len/2;i++){
            if(s[left+i]!=s[right-i]){
                return false;
            }
        }
        return true;
    }
    void rec(int idx,string &s,vector<string>&cur,vector<vector<string>>&ans){
        int n=s.size();
        if(idx>=n){
            ans.push_back(cur);
            return ;
        }
        for(int i=1;i+idx<=n;i++){
            if(isPalindrome(idx,i,s)){
                cur.push_back(s.substr(idx,i));
                rec(idx+i,s,cur,ans);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>cur;
        rec(0,s,cur,ans);
        return ans;
    }
};