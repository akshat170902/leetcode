class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0,res=0;
        for(int i=0;i<n;i++){
            for(int j=m-1-ans;j>=0&&grid[i][j]<0;j--){
                ans++;
            }
            res+=ans;
        }
        return res;
    }
};