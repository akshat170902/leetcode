class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n),post(n),ans(n);
        int p=1,q=1;
        for(int i=0;i<n;i++){
            pre[i]=p;
            p*=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            post[i]=q;
            q*=nums[i];
        }
        for(int i=0;i<n;i++){
            ans[i]=pre[i]*post[i];
        }
        return ans;
    }
};