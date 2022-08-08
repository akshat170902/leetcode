class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(ans.size()==0){
                ans.push_back(nums[i]);
            }
            else{
                int idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                if(idx>=ans.size()){
                    ans.push_back(nums[i]);
                }
                else{
                    ans[idx]=nums[i];
                }
            }
        }
        return ans.size();
    }
};