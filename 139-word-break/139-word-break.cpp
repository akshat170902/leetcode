class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>m;
        for(int i=0;i<wordDict.size();i++)m[wordDict[i]]++;
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size()));
        for(int e=s.size()-1;e>=0;e--){
            string st="";
            for(int i=0; e+i<s.size()&&i<21;i++){
                st+=s[e+i];
                if(m.count(st)>0){
                    dp[e][e+i]=true;
                }
                else{
                    dp[e][e+i]=false;
                }
            }
        }
        for(int i=1;i<=s.size();i++){
            for(int j=0;j+i-1<s.size();j++){
                if(dp[j][j+i-1]!=true){
                for(int k=j;k<j+i-1;k++){
                    dp[j][j+i-1]=dp[j][j+i-1]||(dp[j][k]&&dp[k+1][j+i-1]);
                    }
                }
            }
        }
        return dp[0][s.size()-1];
    }
};