class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,queue<vector<int>>&a,vector<vector<int>>&v){
        int n=grid.size();
        if(i<0||j<0||i>=n||j>=n||vis[i][j]){
            return ;
        }
        vis[i][j]=1;
        if(grid[i][j]){
            a.push({i,j,0});
            v[i][j]=1;
            dfs(i+1,j,grid,vis,a,v);
            dfs(i-1,j,grid,vis,a,v);
            dfs(i,j+1,grid,vis,a,v);
            dfs(i,j-1,grid,vis,a,v);
        }
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<vector<int>>v(n,vector<int>(n,0));
        queue<vector<int>>a;
        bool vaa=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    dfs(i,j,grid,vis,a,v);
                    vaa=true;
                    break;
                }
            }
            if(vaa){
                break;
            }
        }
        vector<pair<int,int>>b={{1,0},{-1,0},{0,1},{0,-1}};
        int ans=1e9;
        cout<<a.size()<<endl;
        while(a.size()){
            vector<int>temp=a.front();
            a.pop();
            int i=temp[0];
            int j=temp[1];
            int d=temp[2];
            for(int k=0;k<b.size();k++){
                int x=b[k].first;
                int y=b[k].second;
                if(i+x>=0&&i+x<n&&j+y>=0&&j+y<n&&v[i+x][j+y]==0){
                    if(grid[i+x][j+y]){
                        cout<<i+x<<" "<<j+y<<endl;
                        ans=min(ans,d);
                    }
                    else{
                        a.push({i+x,j+y,d+1});
                    }
                    v[i+x][j+y]=1;
                }
            } 
            
        }
        return ans;
    }
};