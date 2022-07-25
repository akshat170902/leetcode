class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0,high=height.size()-1;
        int ans=0;
        
        while(low<high){
            ans=max(min(height[low],height[high])*(high-low),ans);
            height[low]<height[high]?low++:high--;
        }
        return ans;
    }
};