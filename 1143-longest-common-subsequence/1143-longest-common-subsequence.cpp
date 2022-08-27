class Solution {
public:
    int rec(int i,int j,string &t,string &s,vector<vector<int>>&dp){
        int n=t.size(),m=s.size();
        if(i>=n||j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take=0;
        if(t[i]==s[j]){
            take=1+rec(i+1,j+1,t,s,dp);
        }
        int notTake=max(rec(i+1,j,t,s,dp),rec(i,j+1,t,s,dp));
        return dp[i][j]=max(take,notTake);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return rec(0,0,text1,text2,dp);
        
    }
};