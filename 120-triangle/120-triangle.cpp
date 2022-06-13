class Solution {
public:
    int rec(vector<vector<int>>&tri,int idx,int j,vector<vector<int>>&dp){
        if(idx>=tri.size()||j>=tri[idx].size()){
            return 0;
        }
        if(idx==tri.size()-1){
            return dp[idx][j]= tri[idx][j];
        }
        if(dp[idx][j]!=-1)return dp[idx][j];
        int take=rec(tri,idx+1,j,dp);
        int nottake=rec(tri,idx+1,j+1,dp);
        return dp[idx][j]= min(take,nottake)+tri[idx][j];
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        return rec(triangle,0,0,dp);
    }
};