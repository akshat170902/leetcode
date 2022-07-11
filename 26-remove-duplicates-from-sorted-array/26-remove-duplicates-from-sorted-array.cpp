class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,j=1,k=1;
        for(i=1;i<nums.size();i++){
            if(nums[i-1]!=nums[i]){
                nums[j]=nums[i];
                k++;
                j++;
            }
        }
        return k;
    }
};