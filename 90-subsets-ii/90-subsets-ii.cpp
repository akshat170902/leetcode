class Solution {
public:
    void rec(vector<int>&nums,int idx,vector<vector<int>>&ans,vector<int>cur){
        
        if(idx==nums.size()){
            
            ans.push_back(cur);
            
            return;
        }
        int take=0,notTake=0;
        for(int i=idx;i<nums.size();i++){
            if(i==idx){
                
                cur.push_back(nums[i]);
                rec(nums,i+1,ans,cur);
                cur.pop_back();
                
            }
            else{
                if(nums[i]==nums[i-1]){
                    continue;
                }
                else{
                    
                    cur.push_back(nums[i]);
                    rec(nums,i+1,ans,cur);
                    cur.pop_back();
                    
                }
            }
            
        }
        rec(nums,nums.size(),ans,cur);
       
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>cur;
        sort(begin(nums),end(nums));
        rec(nums,0,ans,cur);
        return ans;
    }
};