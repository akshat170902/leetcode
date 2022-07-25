class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        
        for(;i>=0;i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        if(i==-1){
            reverse(nums.begin(),nums.end());
            
        }
        else{
            for(int j=n-1;j>i;j--){
                if(nums[j]>nums[i]){
                    swap(nums[i],nums[j]);
                    break;
                }
            }
            reverse(nums.begin()+i+1,nums.end());
        }
    }
};