class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size(),low=0,high=n-1;
        int idx=-1;
        if(nums[low]<=nums[high]){
            return nums[low];
        }
        while(low<high){
            int mid=low+(high-low)/2;
            if(mid<n&&nums[mid]>nums[mid+1]){
                idx=mid+1;
                break;
            }
            if(mid>0&&nums[mid]<nums[mid-1]){
                idx=mid;
                break;
            }
            if(nums[low]<nums[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return nums[idx];
    }
};