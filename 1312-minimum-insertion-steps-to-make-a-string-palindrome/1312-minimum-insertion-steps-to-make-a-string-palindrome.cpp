class Solution {
public:
    int lcs(string &s,string&t){
        int n=s.size();
        int m=t.size();
        vector<int>dp(m+1),prev(m+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[j]=prev[j-1]+1;
                }
                else{
                    dp[j]=max(prev[j],dp[j-1]);
                }
            }
            prev=dp;
        }
        return dp[m];
    }
    int minInsertions(string s) {
        string t=s;
        reverse(begin(t),end(t));
       return s.size()- lcs(s,t);
    }
};