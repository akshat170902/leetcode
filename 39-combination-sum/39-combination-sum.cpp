class Solution {
public:
    void rec(int idx,int tar,vector<int>&c,vector<int>&cur,vector<vector<int>>&ans){
        if(tar==0){
            ans.push_back(cur);
            return;
        }
        if(idx==c.size()||tar<0){
            return;
        }
        rec(idx+1,tar,c,cur,ans);
        cur.push_back(c[idx]);
        rec(idx,tar-c[idx],c,cur,ans);
        cur.pop_back();
        
    }
    vector<vector<int>> combinationSum(vector<int>& c, int tar) {
        vector<int>cur;
        vector<vector<int>>ans;
        sort(c.begin(),c.end());
        rec(0,tar,c,cur,ans);
        return ans;
    }
};