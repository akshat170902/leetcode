class Solution {
public:
    int dx[4] = {1 , -1 ,  0 , 0};
    int dy[4] = {0 ,  0 , -1 , 1};
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        queue<pair<int, int>> q;
        int n = maze.size() , m = maze[0].size();
        vector<vector<bool>> visited(n , vector<bool>(m, 0));   // keeping a visited matrix of the same size as that of the maze to keep track of visited cells
        
        visited[entrance[0]][entrance[1]] = 1;                  // The beginning point should be noted as visited.
        q.push({entrance[0] , entrance[1]});                    // now add it to our queue for a subsequent BFS traversal.
        
        int level = 0;
        
        while( !q.empty() ) {
            
            int size = q.size();
            level++;
            
            while( size-- ) {
                
                pair<int, int> p = q.front();
                q.pop();
                
                for( int i = 0; i < 4; i++ ){
                    
                    int new_row = p.first+dx[i], new_col = p.second+dy[i];
                    
                    if( new_row >= 0 and new_col >= 0 and new_row < n and new_col < m){
                        
                        if(maze[new_row][new_col] != '.') continue;
                        if(visited[new_row][new_col]) continue;                     // if this cell is already visited, don't check further        
                        
                        if( new_row == 0 or new_col==0 or new_row == n-1 or new_col == m-1) return level;       // if we reached a boundary, return the level
                        
                        visited[new_row][new_col] = 1;
                        q.push({new_row, new_col});
                    }
                }
            }
        }
        return -1;
    }
};