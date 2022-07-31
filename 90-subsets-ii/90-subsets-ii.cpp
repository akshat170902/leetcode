class Solution {
public:
    void subset(vector<int>& nums,vector<vector<int>>&ans,int idx,vector<int>cur) {
        
        int n=nums.size();
        if(idx==n){
            ans.push_back(cur);
            return;
        }
        for(int i=idx;i<n;i++){
            if(i!=idx&&nums[i]==nums[i-1]){
                continue;
            }
            else{
                cur.push_back(nums[i]);
                subset(nums,ans,i+1,cur);
                cur.pop_back();
            }
            
        }
        subset(nums,ans,n,cur);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>cur;
        sort(nums.begin(),nums.end());
        subset(nums,ans,0,cur);
        return ans;
    }
};