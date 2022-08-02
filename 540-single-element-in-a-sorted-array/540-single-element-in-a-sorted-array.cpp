class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low+1)/2;
            cout<<low<<mid<<high<<endl;
            if((mid>=n||nums[mid]!=nums[mid+1])&&(mid<=0||nums[mid]!=nums[mid-1])){
                return nums[mid];
            }
            else if(mid%2==0){
                if(mid<n&&nums[mid]==nums[mid+1]){
                    low=mid+1;
                }
                else if(mid>0&&nums[mid]==nums[mid-1]){
                    high=mid-1;
                }
            }
            else{
                if(mid<n&&nums[mid]==nums[mid+1]){
                    high=mid-1;
                }
                else if(mid>0&&nums[mid]==nums[mid-1]){
                    low=mid+1;
                }
            }
        }
        return nums[low];
    }
};