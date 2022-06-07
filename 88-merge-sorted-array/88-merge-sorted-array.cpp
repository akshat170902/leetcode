class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        while(i<m+n&&j<n){
            if(nums1[i]<=nums2[j]){
                 i++;
            }
            else{
                for(int id=nums1.size()-2;id>=i;id--){
                    nums1[id+1]=nums1[id];
                }
                nums1[i]=nums2[j];
                // i++;
                j++;
            }
        }
        // i=j+i;
        cout<<i<<" "<<j<<endl;
        
        if(j<n){
            i=i-n+j;
            while(j<n){
           
           nums1[i]=nums2[j];
           j++;
           i++;
       }
    }
    }
};