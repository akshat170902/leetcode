class Solution {
public:
    bool isValid(string &s,int m,int n){
        if(m+n<s.size()){
            return false;
        }
        return true;
    }
    pair<int,int>calFunc(string s){
        int one=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                one++;
            }
        }
        return {one,s.size()-one};
    }
    int knapSack(int i,vector<pair<int,int>>&arr,int ones,int zeros,vector<vector<vector<int>>>&dp){
        if(i==arr.size()){
            return 0;
        }
        if(dp[i][ones][zeros]!=-1){
            return dp[i][ones][zeros];
        }
        int take=0;
        if(arr[i].first<=ones&&arr[i].second<=zeros){
            take=1+knapSack(i+1,arr,ones-arr[i].first,zeros-arr[i].second,dp);
            
        }
        int notTake=knapSack(i+1,arr,ones,zeros,dp);
        return dp[i][ones][zeros]=max(take,notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>arr;
        for(int i=0;i<strs.size();i++){
            if(isValid(strs[i],m,n)){
                arr.push_back(calFunc(strs[i]));
            }
        }
        vector<vector<vector<int>>>dp(arr.size(),vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        return knapSack(0,arr,n,m,dp);
        
    }
    
};