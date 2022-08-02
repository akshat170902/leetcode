class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size(),low=0,high=n-1;
        int idx=-1;
        if(nums[low]<=nums[high]){
            return low;
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
        return idx;
    }
    int bin(vector<int>&nums,int tar,int low,int high){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==tar){
                return mid;
            }
            else if(nums[mid]<tar){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int tar) {
        int pvt=findMin(nums);
        if(tar<nums[0]){
            return bin(nums,tar,pvt,nums.size()-1);
            
        }
        return bin(nums,tar,0,(pvt-1+nums.size())%nums.size());
    }
};