class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            // cout<<nums[i]<<endl;
            int val=abs(nums[i]);
            if(nums[val-1]<0)
                ans.push_back(val);
            nums[val-1]*=-1;
        }
        return ans;
    }
};