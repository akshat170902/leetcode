class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n-2*i-1;j++){
                int temp=matrix[i+j][n-1-i];
                matrix[i+j][n-1-i]=matrix[i][j+i];
                matrix[i][j+i]=matrix[n-1-j-i][i];
                matrix[n-1-j-i][i]=matrix[n-1-i][n-j-i-1];
                matrix[n-1-i][n-j-i-1]=temp;
            }
        }
    }
};