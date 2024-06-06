class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int>row(n,1),col(m,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!matrix[i][j]){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!row[i]||!col[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};