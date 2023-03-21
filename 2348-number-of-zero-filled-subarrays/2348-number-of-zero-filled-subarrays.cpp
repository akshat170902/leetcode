class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        
        long long sum=0,ans=0;
        
        for(int i=0;i<n;i++){
            int temp=0;
            while(i<n&&nums[i]==0){
                temp++;
                ans+=temp;
                i++;
            }
            
            
        }
        return ans;
    }
};