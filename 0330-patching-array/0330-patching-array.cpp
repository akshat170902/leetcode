class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss=1,i=0,ans=0;
        while(miss<=n){
            if(i<nums.size()&&nums[i]<=miss){
                miss+=nums[i];
                i++;
            }
            else{
                ans++;
                miss+=miss;
            }
        }
        return ans;
    }
};