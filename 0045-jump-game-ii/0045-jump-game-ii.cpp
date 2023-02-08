class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int cur=0,far=0,ans=0;
        for(int i=0;i<n-1;i++){
            cur=max(cur,nums[i]+i);
            if(i==far){
                ans++;
                far=cur;
            }
        }
        return ans;
    }
};