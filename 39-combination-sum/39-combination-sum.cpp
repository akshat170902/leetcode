class Solution {
public:
    void rec(vector<int>&candidates,int tar,vector<vector<int>>&ans,vector<int>cur,int idx){
        int n=candidates.size();
        if(tar<0||idx>=n){
            return ;
        }
        if(tar==0){
            ans.push_back(cur);
            return ;
        }
        cur.push_back(candidates[idx]);
        rec(candidates,tar-candidates[idx],ans,cur,idx);
        cur.pop_back();
        rec(candidates,tar,ans,cur,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>cur;
        sort(candidates.begin(),candidates.end());
        rec(candidates,target,ans,cur,0);
        return ans;
    }
};