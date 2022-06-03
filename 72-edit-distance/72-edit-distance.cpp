class Solution {
public:
    int helper(string&s,string&t,int i,int j,vector<vector<int>>&dp){
    if(i==s.size()&&j==t.size()){
        return 0;
    }
    if(i==s.size())return t.size()-j;
    if(j==t.size())return s.size()-i;
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]= s[i]==t[j]?helper(s,t,i+1,j+1,dp):        min(helper(s,t,i+1,j+1,dp)+1,min(helper(s,t,i+1,j,dp)+1,helper(s,t,i,j+1,dp)+1));
}
 
   

    int minDistance(string str1, string str2) {
         vector<vector<int>>dp(str1.size(),vector<int>(str2.size(),-1));
     return helper(str1,str2,0,0,dp);
    }
};