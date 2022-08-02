class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        if(n>m){
            return findMedianSortedArrays(nums2,nums1);
        }
        int low=0,high=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            int cut2=((n+m+1)/2)-mid;
            
            int left1=mid>0?nums1[mid-1]:INT_MIN;
            int right1=mid==n?INT_MAX:nums1[mid];
            int left2=cut2>0?nums2[cut2-1]:INT_MIN;
            int right2=cut2==m?INT_MAX:nums2[cut2];
            // cout<<low<<mid<<high<<endl;
            if(left1>right2){
                high=mid-1;
            }
            else if(left2>right1){
                low=mid+1;
            }
            else{
                if((n+m)%2){
                    return max(left1,left2);
                }
                else{
                    return (max(left1,left2)+min(right1,right2))/2.0;
                }
            }
        }
        return 0;
    }
};