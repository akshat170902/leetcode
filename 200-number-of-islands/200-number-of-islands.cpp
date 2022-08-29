class Solution {
public:
    void DFS(int i,int j,vector<vector<char>>&grid){
        
        int n=grid.size(),m=grid[0].size();
        if(i<0||i>=n||j<0||j>=m||grid[i][j]=='0'){
            return;
        }
        // cout<<i<<" "<<j<<" "<<grid[i][j]<<endl;
        vector<pair<int,int>>p={{-1,0},{1,0},{0,-1},{0,1}};
        grid[i][j]='0';
        for(int k=0;k<p.size();k++){
            DFS(i+p[k].first,j+p[k].second,grid);
        }
    }
    int numIslands(vector<vector<char>> grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]=='1'){
                    
                    ans++;
                    DFS(i,j,grid);
                }
            }
        }
        return ans;
    }
};