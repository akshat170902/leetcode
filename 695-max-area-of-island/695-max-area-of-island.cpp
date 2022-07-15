class Solution {
public:
    int getArea(vector<vector<int>>&grid,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0){
            return 0;
        }
        int ans=1;
        grid[i][j]=0;
        ans+=getArea(grid,i+1,j);
        ans+=getArea(grid,i-1,j);
        ans+=getArea(grid,i,j+1);
        ans+=getArea(grid,i,j-1);
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    ans=max(ans,getArea(grid,i,j));
                }
            }
        }
        return ans;
    }
};