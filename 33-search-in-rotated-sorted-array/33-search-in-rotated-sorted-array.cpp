class Solution {
public:
    int bin_search(vector<int>&nums,int lo,int hi,int tar){
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]==tar)return mid;
            else if(nums[mid]<tar)lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        
        int lo=0,hi=nums.size()-1;
        if(nums[lo]<=nums[hi]){
            return bin_search(nums,lo,hi,target);
        }
        int pvt=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>nums[mid+1]){
                pvt=mid+1;
                break;
            }
            if(nums[mid]<nums[mid-1]){
                pvt=mid;
                break;
            }
            if(nums[mid]>nums[lo]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        // cout<<pvt<<endl;
        int l1=bin_search(nums,0,pvt-1,target);
        int l2=bin_search(nums,pvt,n-1,target);
        return (l1==-1)==(l2==-1)?-1:l1==-1?l2:l1;
    }
};