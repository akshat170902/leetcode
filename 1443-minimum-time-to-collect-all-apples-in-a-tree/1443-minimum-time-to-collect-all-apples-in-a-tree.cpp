class Solution {
public:
    bool dfs(vector<vector<int>>&e,int n,vector<bool>&a,vector<bool>&vis,int &sum,int val=0){
        vis[val]=true;
        
        cout<<endl<<val<<" ";
        bool flag=false;
        for(int i=0;i<e[val].size();i++){
            if(!vis[e[val][i]]){
                int temp=0;
                bool ans=dfs(e,n,a,vis,temp,e[val][i]);
                flag=flag||ans;
                if(ans){
                    // cout<<val<<"val";
                    sum+=temp+2;
                    
                }
            }
        }
        cout<<sum;
        return a[val]||flag;
    }
    int minTime(int n, vector<vector<int>>& e, vector<bool>& a) {
        vector<vector<int>>v(n);
        for(int i=0;i<e.size();i++){
            v[e[i][0]].push_back(e[i][1]);
            v[e[i][1]].push_back(e[i][0]);

        }
        int sum=0;
        vector<bool>vis(n,false);
        dfs(v,n,a,vis,sum);
        return sum;
    }
};