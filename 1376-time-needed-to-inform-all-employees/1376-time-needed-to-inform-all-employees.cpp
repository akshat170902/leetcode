class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& m, vector<int>& iT) {
        vector<vector<int>>g(n);
        for(int i=0;i<m.size();i++){
            if(i==headID){
                continue;
            }
            g[m[i]].push_back(i);
        }
        int ans=0;
        queue<pair<int,int>>q;
        q.push({headID,0});
        while(q.size()){
            auto [node,cur] =q.front();
            q.pop();
            if(!g[node].size()){
               ans=max(ans,cur); 
            }
            else{
                for(auto&child:g[node]){
                    q.push({child,cur+iT[node]});
                }
            }
        }
        return ans;
    }
};