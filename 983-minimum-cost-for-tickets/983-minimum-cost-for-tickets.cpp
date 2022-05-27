class Solution {
public:
    int  helper(int idx,int val,vector<int>&days,vector<int>&costs,vector<int>&dp){
       
        while(idx<days.size()&&days[idx]<val){
            idx++;
        }
         if(idx>=days.size()||val>365){
            return 0;
        }
        if(dp[idx]==0){
            dp[idx]=min(helper(idx+1,days[idx]+1,days,costs,dp)+costs[0],min(helper(idx+1,days[idx]+7,days,costs,dp)+costs[1],helper(idx+1,days[idx]+30,days,costs,dp)+costs[2]));
        }
        return dp[idx];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1);
        return helper(0,0,days,costs,dp);
      
    }
};