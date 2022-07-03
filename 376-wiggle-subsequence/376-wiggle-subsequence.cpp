class Solution {
public:
    int rec(int prev,int idx,vector<int>&nums,bool flag,vector<vector<vector<int>>>&dp){
        
        if(idx>=nums.size())return 0;
        // cout<<nums[idx]<<" "<<idx<<endl;
        if(dp[prev+1][idx][flag]!=-1)return dp[prev+1][idx][flag];
        int take=0,notTake=0,same=0;
        if(prev==-1){
            take=rec(idx,idx+1,nums,true,dp)+1;
            notTake=rec(idx,idx+1,nums,false,dp)+1;
            
        }
        else if(flag){
            // 
            if(nums[prev]<nums[idx]){
                take=rec(idx,idx+1,nums,false,dp)+1;
            }
            notTake=rec(prev,idx+1,nums,true,dp);
        }
        else{
            // cout<<nums[idx]<<" "<<idx<<endl;
            if(nums[prev]>nums[idx]){
                take=rec(idx,idx+1,nums,true,dp)+1;
            }
            notTake=rec(prev,idx+1,nums,false,dp);
        }
        // cout<<idx<<" "<<flag<<" "<<take<<endl;
        return dp[prev+1][idx][flag]= max(take,notTake);
    }
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<vector<int>>>dp(nums.size()+1,vector<vector<int>>(nums.size()+1,vector<int>(2,-1)));
        return rec(-1,0,nums,true,dp);
    }
};