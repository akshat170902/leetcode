class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        for(int j=0;j<nums.size();){
            if(nums[j]==0){
                j++;
            }
            else{
                nums[i]=nums[j];
                i++;
                j++;
                
            }
        }
        for(i;i<nums.size();i++){
            nums[i]=0;
        }
    }
};