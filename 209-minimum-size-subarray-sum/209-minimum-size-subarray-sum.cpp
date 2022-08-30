class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0,high=0;
        int curSum=0,maxLength=1e9;
        while(low<nums.size()&&low<=high){
            // cout<<low<<" "<<high<<endl;
            if(curSum>=target){
                maxLength=min(maxLength,high-low);
                curSum-=nums[low];
                low++;
            }
            else{
                if(high<nums.size())
                curSum+=nums[high++];
                else
                    break;
            }
        }
        return maxLength==1e9?0:maxLength;
    }
};