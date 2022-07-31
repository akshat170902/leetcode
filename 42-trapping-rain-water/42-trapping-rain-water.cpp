class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),ans=0;
        int left=0,right=n-1;
        int Lmax=0,Rmax=0;
        while(left<right){
            Lmax=max(Lmax,height[left]);
            Rmax=max(Rmax,height[right]);
            
            if(height[left]<=height[right]){
                
                ans+=min(Rmax,Lmax)-height[left];
                left++;
            }
            else{
                
                ans+=min(Rmax,Lmax)-height[right];
                right--;
            }
        }
        return ans;
    }
};