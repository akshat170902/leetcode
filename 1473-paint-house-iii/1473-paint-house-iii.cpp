class Solution {
public:
    int rec(int idx,int prev,int cur,vector<int>&house,vector<vector<int>>&cost,int m,int n,int tar,vector<vector<vector<int>>>&dp){
        if(idx==m&&cur==tar)return 0;
        if(idx>=m||cur>tar)return 1e9;
        if(dp[idx][prev][cur]!=-1)return dp[idx][prev][cur];
        int ans=1e9;
        if(house[idx]){
            if(prev!=house[idx]){
                ans=rec(idx+1,house[idx],cur+1,house,cost,m,n,tar,dp);
            }
            else{
                ans=rec(idx+1,house[idx],cur,house,cost,m,n,tar,dp);
            }
        }
        else{
            int curCost=1e9;
            for(int i=0;i<n;i++){
                if(i+1==prev){
                    curCost=rec(idx+1,i+1,cur,house,cost,m,n,tar,dp)+cost[idx][i];
                }
                else{
                    curCost=rec(idx+1,i+1,cur+1,house,cost,m,n,tar,dp)+cost[idx][i];
                }
                ans=min(ans,curCost);
            }
        }
        return dp[idx][prev][cur]=ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n+1,vector<int>(target+1,-1)));
        int ans= rec(0,0,0,houses,cost,m,n,target,dp);
        return ans==1e9?-1:ans;
    }
};