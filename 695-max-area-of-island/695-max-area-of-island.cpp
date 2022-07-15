class Solution {
public:
    int getArea(vector<vector<int>>&grid,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0){
            return 0;
        }
        int ans=1;
        grid[i][j]=0;
    int a=getArea(grid,i+1,j),b=getArea(grid,i-1,j),c=getArea(grid,i,j+1),d=getArea(grid,i,j-1);
        if(a)ans+=a;
        if(b)ans+=b;
        if(c)ans+=c;
        if(d)ans+=d;
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