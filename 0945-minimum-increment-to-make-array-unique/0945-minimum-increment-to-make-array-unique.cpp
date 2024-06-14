class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int val=0,cur=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                nums[i]++;
                val++;
            }
            else if(nums[i]<nums[i-1]){
                val+=nums[i-1]-nums[i]+1;
                nums[i]=nums[i-1]+1;
            }
            
        }
        return val;
    }
};