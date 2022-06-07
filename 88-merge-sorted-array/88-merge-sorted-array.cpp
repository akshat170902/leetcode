class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0){
            return;
        }
        if(m==0){
            for(int b=0;b<n;b++){
                nums1[b]=nums2[b];
                
            }
            return;
        }
        int i=0;
            int j=0;
        if(n==1){
            for(int g=0;g<m;g++){
                if(nums1[g]>nums2[0]){
                     for(int k=m+n-2;k>=g;k--){
                 nums1[k+1]=nums1[k];
             }
             nums1[g]=nums2[0];
                    return;
                }
            }
            nums1[m]=nums2[0];
        }
        while(i-j!=m){
        if(i==m+n||j==n){
            return;
        }
           if(nums1[i]<=nums2[j]){
                i++;
            }
         else {
                
             for(int k=m+n-2;k>=i;k--){
                 nums1[k+1]=nums1[k];
             }
             nums1[i]=nums2[j];
             j++;
             i++;
            }
        }
           while (i<n+m){
               nums1[i]=nums2[j];
               i++;
               j++;
           }     
        
    }
};