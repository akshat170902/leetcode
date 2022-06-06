class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int>dp(s.size()+1);
        int ans=0;
        for(int i=1;i<dp.size();i++){
            if(i==1)continue;
            
            if(s[i-1]==')'&&i-dp[i-1]-2>=0&&s[i-dp[i-1]-2]=='('){
                dp[i]=2+dp[i-dp[i-1]-2]+dp[i-1];
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};