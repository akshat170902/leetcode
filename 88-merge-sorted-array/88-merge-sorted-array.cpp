class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i=m-1,j=m+n-1;i>=0;i--,j--){
            swap(nums1[i],nums1[j]);
        }
        int k=n,i=0,j=0;
        
        while(i<n+m&&j<n){
            if(k<n+m&&nums1[k]<=nums2[j]){
                nums1[i]=nums1[k];
                k++;
            }
            else{
                nums1[i]=nums2[j];
                j++;
            }
            i++;
        }
        
    }
};