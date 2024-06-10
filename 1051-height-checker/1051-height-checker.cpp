class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>sorted=heights;
        int ans=0;
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<heights.size();i++){
            ans+=(heights[i]!=sorted[i]);
        }
        return ans;
    }
};