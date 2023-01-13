class Solution {
public:
    int dfs(int node,vector<vector<int>>&g,string&s,vector<int>&vis,int& ans){
        vis[node]=1;
        vector<int>temp;
        for(int child:g[node]){
            if(!vis[child]){
                int val=dfs(child,g,s,vis,ans);
                if(s[child]!=s[node]){
                    temp.push_back(val);
                }
            }
        }
        int maximum=0,val=0;
        sort(temp.begin(),temp.end(),greater<int>());
        for(int i=0;i<2&&i<temp.size();i++){
            maximum+=temp[i];
            val=max(val,temp[i]);
        }
        ans=max(ans,maximum+1);
        return val+1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=s.size();
        vector<vector<int>>g(n);
        for(int i=1;i<n;i++){
            g[i].push_back(parent[i]);
            g[parent[i]].push_back(i);
        }
        vector<int>vis(n);
        int res=0;
        int ans=dfs(0,g,s,vis,res);
        
        return max(res,ans);
    }
};