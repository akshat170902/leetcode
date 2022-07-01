class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>row(matrix.size()),column(matrix[0].size());
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    column[j]=1;
                }
            }
        }
        for(int i=0;i<row.size();i++){
            if(row[i]){
                for(int j=0;j<column.size();j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<column.size();i++){
            if(column[i]){
               for(int j=0;j<row.size();j++){
                    matrix[j][i]=0;
                } 
            }
        }
    }
};