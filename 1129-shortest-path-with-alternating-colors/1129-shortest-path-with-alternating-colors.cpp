class Solution {
public:
    void dfs(int node,vector<vector<int>>&red,vector<vector<int>>&blue,vector<int>&ans,vector<vector<int>>&vis,int color,int val=0){
        cout<<node<<" "<<color<<" "<<val<<endl;
        vis[color][node]=0;
        ans[node]=min(ans[node],val);
        if(color==0){
            for(auto&neig:red[node]){
                if(vis[1-color][neig]){
                    dfs(neig,red,blue,ans,vis,1-color,val+1);
                }
            }
        }
        if(color==1){
            for(auto&neig:blue[node]){
                if(vis[1-color][neig]){
                    dfs(neig,red,blue,ans,vis,1-color,val+1);
                }
            }
        }
    }
    vector<int>shortestAlternatingPaths(int n, vector<vector<int>>&r, vector<vector<int>>&b){
        vector<vector<int>>blue(n),red(n);
        for(int i=0;i<r.size();i++){
            red[r[i][0]].push_back(r[i][1]);
        }
        for(int i=0;i<b.size();i++){
            blue[b[i][0]].push_back(b[i][1]);
        }
        vector<int>ans(n,1e9);
        vector<vector<int>>vis(2,vector<int>(n,1));
        // dfs(0,red,blue,ans,vis,0);
        // dfs(0,red,blue,ans,vis,1);
        
        queue<vector<int>>q;
        q.push({0,0,0});
        q.push({0,1,0});
        
        while(!q.empty()){
            vector<int>tup=q.front();
            int color=tup[1],node=tup[0],val=tup[2];
            q.pop();
            vis[color][node]=0;
            ans[node]=min(ans[node],val);
            if(color==0){
                for(auto&neig:red[node]){
                    if(vis[1-color][neig]){
                        vector<int>temp={neig,1-color,val+1};
                        q.push(temp);
                    }
                }
            }
            if(color==1){
                for(auto&neig:blue[node]){
                    if(vis[1-color][neig]){
                        vector<int>temp={neig,1-color,val+1};
                        q.push(temp);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(ans[i]==1e9){
                ans[i]=-1;
            }
        }
        return ans;
    }
};