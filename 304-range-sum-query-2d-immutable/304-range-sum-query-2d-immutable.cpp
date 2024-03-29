class NumMatrix {
    vector<vector<int>>dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        dp=matrix;
        for(int i=0;i<matrix.size();i++){
            int sum=0;
            for(int j=0;j<matrix[0].size();j++){
                sum=matrix[i][j];
                dp[i][j]=i>0?dp[i-1][j]+sum:sum;
                cout<<dp[i][j]<<" ";
                
            }
            cout<<endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=col1;i<=col2;i++){
            sum+=row1>0?dp[row2][i]-dp[row1-1][i]:dp[row2][i];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */