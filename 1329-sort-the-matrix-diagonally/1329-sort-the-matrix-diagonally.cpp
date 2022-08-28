class Solution {
public:
    void diagonalSorter(int i,int j,vector<vector<int>>&mat){
        int m=mat.size(),n=mat[0].size();
        priority_queue<int>arr;
        
        for(;i<m&&j<n;i++,j++){
            // cout<<i<<" "<<j<<endl;
            arr.push(mat[i][j]);
        }
        i--,j--;
        for(;i>=0&&j>=0;i--,j--){
            mat[i][j]=arr.top();
            arr.pop();
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>> mat) {
        int m=mat.size(),n=mat[0].size();
        
        for(int i=m-1,j=0;i>=0&&j<n;i==0?j++:i--){
            diagonalSorter(i,j,mat);
            
        }
        
        return mat;
    }
};