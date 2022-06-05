class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        vector<int>l(height.size()),r(height.size());
        l[0]=height[0];
        r[height.size()-1]=height[height.size()-1];
        for(int i=1;i<height.size();i++){
             l[i]=max(l[i-1],height[i]);
            r[height.size()-i-1]=max(r[height.size()-i],height[height.size()-1-i]);
            cout<<l[i]<<" "<<r[height.size()-i-1]<<endl;
        }
         for(int i=1;i<height.size()-1;i++){
             ans+=((min(l[i-1],r[i+1])-height[i])>0?min(l[i-1],r[i+1])-height[i]:0);
         }
        return ans;
    }
};