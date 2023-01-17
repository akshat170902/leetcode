class Solution {
public:
    int func(int idx,string&s,char ch,vector<vector<int>>&dp){
        int n=s.size();
        if(idx>=n){
            return 0;
        }
        if(dp[idx][ch-'0']!=-1){
            return dp[idx][ch-'0'];
        }
        int res1=1e9,res2=1e9;
        if(ch=='0'){
            if(s[idx]=='0'){
                res1=func(idx+1,s,s[idx],dp);
                res2=func(idx+1,s,'1',dp)+1;
            }
            else{
                res1=func(idx+1,s,s[idx],dp);
                res2=func(idx+1,s,'0',dp)+1;
            }
        }
        else{
            if(s[idx]=='0'){
                res1=func(idx+1,s,'1',dp)+1;
            }
            else{
                res1=func(idx+1,s,s[idx],dp);
            }
        }
        return dp[idx][ch-'0']=min(res1,res2);
    }
    
    int minFlipsMonoIncr(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(2,-1));
        int ans=func(0,s,'0',dp);
        return ans;
        
    }
};