class Solution {
public:
    int func(int idx,vector<pair<int,int>>&val,vector<vector<int>>&dp,int prev){
        int n=val.size();
        if(idx>=n){
            return 0;
        }
        if(dp[idx][prev+1]!=-1){
            return dp[idx][prev+1];
        }
        int take=0,notTake=0;
        if(prev==-1||val[idx].second>=val[prev].second){
            take=func(idx+1,val,dp,idx)+val[idx].second;
        }
        notTake=func(idx+1,val,dp,prev);
        // cout<<take<<" "<<notTake<<endl;
        return dp[idx][prev+1]=max(take,notTake);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>val;
        int n=ages.size();
        for(int i=0;i<n;i++){
            val.push_back({ages[i],scores[i]});
            
        }
        sort(val.begin(),val.end());
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return func(0,val,dp,-1);
       
    }
};