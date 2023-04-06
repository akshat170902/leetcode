class Solution {
public:
    bool dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        int n=grid.size(),m=grid[0].size();
        cout<<i<<" "<<j<<endl;
        if(grid[i][j]){
            vis[i][j]=0;
            return true;
        }
        
        if(i<=0||i>=n-1||j<=0||j>=m-1){
            vis[i][j]=0;
            return false;
        }
        if(vis[i][j]==0){
            return true;
        }
        vis[i][j]=0;
        bool flag=true;
        for(int idx=-1;idx<2;idx++){
            if(idx==0){
                continue;
            }
            flag&=dfs(i+idx,j,grid,vis);
            
        }
        for(int idx=-1;idx<2;idx++){
            if(idx==0){
                continue;
            }
            
            flag&=dfs(i,j+idx,grid,vis);
            
        }
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),1));
        for(int i=1;i<grid.size()-1;i++){
            for(int j=1;j<grid[0].size()-1;j++){
                if(vis[i][j]&&grid[i][j]==0){
                    ans+=dfs(i,j,grid,vis);
                    cout<<endl;
                }
            }
        }
        return ans;
    }
};