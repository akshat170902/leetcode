class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0,hi=nums.size()-1;
        int pvt=-1;
        if(hi==0)return nums[hi];
        if(nums[lo]<nums[hi])return nums[lo];
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(mid==0){
                if(nums[0]>nums[1]){
                    pvt=1;
                    break;
                }
            }
            if(nums[mid]<nums[mid+1]&&nums[mid]>nums[mid-1]){
                if(nums[mid]>nums[lo]){
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
            else if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]){
                pvt=mid+1;
                break;
            }
            else{
                pvt=mid;
                break;
            }
        }
        return nums[pvt];
    }
};