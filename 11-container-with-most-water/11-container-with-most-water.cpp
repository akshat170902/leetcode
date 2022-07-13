class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=0,left=0,right=n-1;
        while(left<right){
            ans=max(ans,min(height[left],height[right])*(right-left));
            height[left]<height[right]?left++:right--;
        }
        return ans;
    }
};