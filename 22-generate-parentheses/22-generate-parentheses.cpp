class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>>dp(n+1);
        dp[0].push_back("");
        for(int i=1;i<=n;i++){
            unordered_map<string,int>m;
           for(int j=1;j<i;j++){
               for(int k=0;k<dp[j].size();k++){
                   for(int l=0;l<dp[i-j].size();l++){
                       m[dp[j][k]+dp[i-j][l]]++;
                   }
               }
               
           }
        for(int j=0;j<dp[i-1].size();j++){
                   m["("+dp[i-1][j]+")"]++;
               }
            for(auto it=m.begin();it!=m.end();it++){
                dp[i].push_back(it->first);
            }
        }
        return dp[n];
    }
};