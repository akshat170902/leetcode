class Solution {
public:
   int helper(string &s, vector<int> &dp, int idx = 0)
{
    if (idx >= s.size())
    {
        return 0;
    }
       if(s[idx]=='0'){
           return dp[idx]=-1;
       }
       if (dp[idx] == 0)
    {
    if(idx==s.size()-1){
        if(s[idx]=='0')return dp[idx]=-1;
        return dp[idx]=1;
    }
    if(idx==s.size()-2){
       int next= helper(s,dp,idx+1);
        if(s[idx]=='0')return dp[idx]=-1;
        else if(next!=-1){
           
            if(s[idx]=='1')return dp[idx]=1+next;
            else if(s[idx]=='2'&&s[idx+1]>='0'&&s[idx+1]<='6')return dp[idx]=1+next;
            else return dp[idx]=next;
        }
        else {
             cout<<s[idx];
             if(s[idx]=='1')return dp[idx]=1;
            else if(s[idx]=='2'&&s[idx+1]>='0'&&s[idx+1]<='6')return dp[idx]=1;
            else return dp[idx]=next;
        }
    }
    
        int l=helper(s, dp, idx + 1);
        int r=helper(s, dp, idx + 2);
         if(l!=-1&&r!=-1){
             if((s[idx]=='1')||(s[idx]=='2'&&s[idx+1]>='0'&&s[idx+1]<='6')){
                 dp[idx]=dp[idx+1]+dp[idx+2];
             }
             else{
                 dp[idx]=dp[idx+1];
             }
         }
         else if(l!=-1){
             dp[idx]=dp[idx+1];
         }
         else if(r!=-1){
             if((s[idx]=='1')||(s[idx]=='2'&&s[idx+1]>='0'&&s[idx+1]<='6')){
             dp[idx]=dp[idx+2];
             }
             else{
                 dp[idx]=-1;
             }
         }
         else{
            dp[idx]=-1;
         }
    }
    return dp[idx];
}
 int numDecodings(string s) {
        vector<int>dp(s.size());
        helper(s,dp);
     if(dp[0]==-1){
         return 0;
     }
        return dp[0];
    }
};