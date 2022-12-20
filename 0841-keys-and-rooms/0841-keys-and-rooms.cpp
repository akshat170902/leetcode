class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int qs = q.size();
            while(qs--){
                int cur_room =q.front();
                q.pop();
                for(int key:rooms[cur_room]){
                    if(!vis[key]){
                        vis[key]=1;
                        q.push(key);
                    }
                }
            }
        }
        if(find(vis.begin(),vis.end(),0)!=vis.end()){// checking is there any room not visited
            return false;
        } 
        return true;
        
    }
};