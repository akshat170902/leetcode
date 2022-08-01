class Solution {
public:
    bool isSafe(int &row,int &col,vector<string>&cur){
        for(int i=row;i>=0;i--){
            if(cur[i][col]=='Q')return false;
        }
        for(int i=col,j=row;i<cur.size()&&j>=0;i++,j--){
            if(cur[j][i]=='Q')return false;
        }
        for(int i=col,j=row;i>=0&&j>=0;i--,j--){
            if(cur[j][i]=='Q')return false;
        }
        return true;
    }
    void solve(int idx,vector<vector<string>>&ans,vector<string>&cur,int n){
        if(idx==n){
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(idx,i,cur)){
                cur[idx][i]='Q';
                solve(idx+1,ans,cur,n);
                cur[idx][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s="";
        for(int i=0;i<n;i++)s+='.';
        vector<string>cur(n,s);
        solve(0,ans,cur,n);
        return ans;
    }
};