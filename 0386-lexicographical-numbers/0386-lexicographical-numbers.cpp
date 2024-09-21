class Solution {
public:
    void dfs(int cur,int lim,vector<int>&v){
        
        v.push_back(cur);
        for(int i=0;i<=9;i++){
            if(cur*10+i<=lim){
                dfs(cur*10+i,lim,v);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>v;
        for(int i=1;i<=min(9,n);i++){
            dfs(i,n,v);
        }
        return v;
    }
};