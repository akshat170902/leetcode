class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<long long>>s,dp(n,vector<long long>(m,1)),p={{1,0},{0,1},{-1,0},{0,-1}};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                s.push_back({grid[i][j],i,j});
            }
        }
        
        sort(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            int x=s[i][1],y=s[i][2],val=s[i][0];
            for(int j=0;j<p.size();j++){
                int dx=p[j][0]+x,dy=p[j][1]+y;
                if(dx>=0&&dy>=0&&dx<n&&dy<m&&grid[dx][dy]>grid[x][y]){
                    dp[dx][dy]=(dp[dx][dy]+dp[x][y])%(1000000007);
                }
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=(ans+dp[i][j])%(1000000007);
            }
        }
        return ans;
    }
};