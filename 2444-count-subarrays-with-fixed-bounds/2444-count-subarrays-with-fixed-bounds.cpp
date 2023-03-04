class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        int lower=-1;
        long long ans=0;
        int first=-1,last=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==minK){
                first=i;
            }
            if(nums[i]==maxK){
                last=i;
            }
            if(nums[i]<minK||nums[i]>maxK){
                lower=i;
                first=-1;
                last=-1;
            }
            int val=(min(first,last)-lower);
            if(val>0){
                ans+=val;
            }
        }
        
        
        
        return ans;
    }
};