class Solution {
public:
    
    int longestCommonSubsequence(string t, string s) {
        int n=t.size(),m=s.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int take=0;
                if(t[i]==s[j]){
                    take=1+dp[i+1][j+1];
                }
                int notTake=max(dp[i][j+1],dp[i+1][j]);
                dp[i][j]=max(take,notTake);
            }
        }
        return dp[0][0];
        
    }
};