class Solution {
public:
    bool isSafe(int col,int n,vector<int>&d1,vector<int>&d2,int row,vector<vector<int>>&chess){
        if(d1[row+col]!=-1)return false;
        if(d2[row-col+n-1]!=-1)return false;
        for(int i=0;i<row;i++){
            if(chess[i][col]!=0)return false;
        }
        return true;
    }
    int func(int n,int row,vector<int>&d1,vector<int>&d2,vector<vector<int>>&chess){
        if(row==n)return 1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(isSafe(i,n,d1,d2,row,chess)){
                chess[row][i]=1;
                d1[row+i]=1;
                d2[row-i+n-1]=1;
                sum+=func(n,row+1,d1,d2,chess);
                chess[row][i]=0;
                d1[row+i]=-1;
                d2[row-i+n-1]=-1;
            }
               }
    return sum;
    }
         
    
    int totalNQueens(int n) {
        vector<int>d1(2*n-1,-1),d2(2*n-1,-1);
        vector<vector<int>>chess(n,vector<int>(n));
        return func(n,0,d1,d2,chess);
    }
};