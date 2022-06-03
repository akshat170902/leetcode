class Solution {
public:
    int helper(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(i==s.size()&&j==t.size()){
        return 1;
    }
    if(i==s.size())return 0;
    if(j==t.size()){
        if(s[i]=='*'){
            return dp[i][j]= helper(i+1,j,s,t,dp);
        }
        else{
            return  0;
        }
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]||s[i]=='?'){
        return dp[i][j]= helper(i+1,j+1,s,t,dp);
    }
    if(s[i]=='*'){
        return dp[i][j]= helper(i,j+1,s,t,dp)||helper(i+1,j,s,t,dp);
    }
        return 0;
}
 bool isMatch(string pattern, string text) {
    vector<vector<int>>dp(text.size()+1,vector<int>(pattern.size()+1,-1));
    return helper(0,0,text,pattern,dp)==1?true:false;
}
};