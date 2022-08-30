class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxR=0;
        for(int i=0;i<=maxR;i++){
            // cout<<maxR<<" "<<i<<endl;
            if(i+nums[i]>maxR){
                maxR=i+nums[i];
            }
            if(maxR>=nums.size()-1){
                return true;
            }
        }
        return false;
    }
};