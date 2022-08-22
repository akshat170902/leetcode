class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>>arr={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int sz=q.size();
            ans++;
            for(int l=0;l<sz;l++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<arr.size();k++){
                    int x=i+arr[k].first;
                    int y=j+arr[k].second;
                    if(x<0||y<0||x>=m||y>=n||grid[x][y]!=1){
                        continue;
                    }
                    grid[x][y]=2;
                    q.push({x,y});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return max(0,ans-1);
    }
};