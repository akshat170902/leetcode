class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        int v=nums2.size(),n=nums1.size();
        m[nums2[v-1]]=-1;
        for(int i=v-2;i>=0;i--){
            if(nums2[i+1]<nums2[i]){
                int cur=m[nums2[i+1]];
                while(cur!=-1&&nums2[i]>cur){
                    cur=m[cur];
                }
                m[nums2[i]]=cur;
            }
            else{
                m[nums2[i]]=nums2[i+1];
            }
        }
        for(int i=0;i<n;i++){
            nums1[i]=m[nums1[i]];
        }
        return nums1;
    }
};