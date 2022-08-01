class Solution {
public:
    void rec(int idx,vector<int>&cur,vector<vector<int>>&ans,vector<int>&c,int tar){
        int n=c.size();
        if(idx>n||tar<0){
            return ;
        }
        if(tar==0){
            ans.push_back(cur);
        }
        for(int i=idx;i<n;i++){
            if(i!=idx&&c[i]==c[i-1]){
                continue;
            }
            cur.push_back(c[i]);
            rec(i+1,cur,ans,c,tar-c[i]);
            cur.pop_back();
            // rec(i+1,cur,ans,c,tar);
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        vector<vector<int>>ans;
        vector<int>cur;
        rec(0,cur,ans,c,target);
        return ans;
    }
};