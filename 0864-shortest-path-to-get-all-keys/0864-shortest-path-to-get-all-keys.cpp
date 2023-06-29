class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<bool>> visited(n*m,vector<bool>(64,0)); //at most 6 keys, using bitmap 111111
        queue<pair<int,int>> q;
        int k=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='@'){
                    q.push({i*m+j,0}); // marking starting position
                    visited[i*m+j][k]=true;
                }else if(grid[i][j]>='A' && grid[i][j]<='F'){
                    k++;
                }
            }
        }
        
        int steps=0;
        int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        while(q.size()>0){
            int size=q.size();
            while(size--){
                pair<int,int> p=q.front();
                q.pop();
                
                int i=p.first/m, j=p.first%m;
                int carry=p.second;
                
                if(carry == ((1<<k)-1)) return steps;
                
                for(int d=0;d<4;d++){
                    int x=i+dxy[d][0], y=j+dxy[d][1];
                    
                    if(x<0 || y<0 || x==n || y==m || grid[x][y]=='#') continue;
                    
                    int new_carry=carry;
                    if(grid[x][y]>='a' && grid[x][y]<='f'){
                        new_carry = carry | (1<<(grid[x][y]-'a')); //update hold keys
                    }else if(grid[x][y]>='A' && grid[x][y]<='F'){
                        if(!(carry & (1<<(grid[x][y]-'A')))) continue; // if key corresponding to new lock is not present, we will not move forward
                    }
                    
                    if(visited[x*m+y][new_carry]==false){
                        visited[x*m+y][new_carry]=true;
                        q.push({x*m+y,new_carry});
                    }  
                } 
            }
            steps++;
        }
        
        return -1;
    }
};