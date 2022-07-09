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
        for(int i=idx;i<c.size();i++){
            if(i==idx){
                cur.push_back(c[i]);
                rec(i+1,tar-c[i],c,cur,ans);
                cur.pop_back();
                
            }
            else{
                if(c[i]==c[i-1]){
                    continue;
                }
                else{
                    cur.push_back(c[i]);
                    rec(i+1,tar-c[i],c,cur,ans);
                    cur.pop_back();
                }
            }
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int tar) {
        vector<int>cur;
        vector<vector<int>>ans;
        sort(c.begin(),c.end());
        rec(0,tar,c,cur,ans);
        return ans;
    }
};