class Solution {
public:
    int trap(vector<int>& height) {
        int lo=0,hi=height.size()-1;
        int res=0;
        int leftmax=0,rightmax=0;
        while(lo<hi){
            if(height[lo]<=height[hi]){
                leftmax=max(height[lo],leftmax);
                res+=leftmax-height[lo];
                lo++;
            }
            else{
                rightmax=max(height[hi],rightmax);
                res+=rightmax-height[hi];
                hi--;
            }
        }
        return res;
    }
};