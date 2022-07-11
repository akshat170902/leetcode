class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        int cur=0;
        for(int i=0;i<nums.size();i++){
            int temp=cur;
            cur+=nums[i];
            if(sum-cur==temp){
                return i;
            }
        }
        return -1;
    }
};