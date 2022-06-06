class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(p.size()+1,vector<int>(s.size()+1));
         dp[p.size()][s.size()]=1;
        for(int i=p.size()-1;i>=0;i--){
            for(int j=s.size();j>=0;j--){
               if(j==s.size()) {if(p[i]=='*'){
                    dp[i][j]=dp[i+1][j];
                }
                                
                               else if(i<p.size()-1&&p[i+1]=='*'){
                        dp[i][j]=dp[i+2][j];
                    }
                else{
                    dp[i][j]=0;
                }}
               else if(s[j]==p[i]||p[i]=='.'){
                   int take=i<p.size()?p[i+1]=='*'?dp[i+2][j]:0:0;
                   dp[i][j]=dp[i+1][j+1]||take;
               }
                else if(p[i]=='*'){
                    int take=i>0?(p[i-1]==s[j]||p[i-1]=='.')?dp[i][j+1]:0:0;
                     dp[i][j]=dp[i+1][j]||take;
                }
                else{
                    if(i<p.size()-1&&p[i+1]=='*'){
                        dp[i][j]=dp[i+2][j];
                    }
                }
            }
        }
        // for(int i=0;i<dp.size();i++){
            if(dp[0][0]==1)return true;
        // }
        return false;
    }
};