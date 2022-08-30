class Solution {
public:
    bool Safe(int row,int col,vector<vector<char>>&board){
        if(board[row][col]=='.'){
            return true;
        }
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            
            if(board[row][col]==board[i][col]&&i!=row){
                return false;
            }
            if(board[row][col]==board[row][i]&&i!=col){
                return false;
            }
            if(board[row][col]==board[row-row%3+i/3][col-col%3+i%3]&&row%3!=i/3&&col%3!=i%3){
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<i<<" "<<j<<endl;
                if(!Safe(i,j,board)){
                    return false;
                }
            }
        }
        return true;
    }
};