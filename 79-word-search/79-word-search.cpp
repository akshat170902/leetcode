class Solution {
public:
    bool rec(int i,int j,int idx,vector<vector<char>>&board,string word){
        if(idx==word.size()){
            return true;
        }
        if(i<0||j<0||i>=board.size()||j>=board[0].size()){
            return false;
        }
        
        // cout<<board[i][j]<<" ";
        if(board[i][j]==word[idx]){
            board[i][j]='.';
            bool flag= rec(i+1,j,idx+1,board,word)||rec(i,j+1,idx+1,board,word)||rec(i-1,j,idx+1,board,word)||rec(i,j-1,idx+1,board,word);
            board[i][j]=word[idx];
            if(flag)return true;
        }
        if(idx!=0){
            return false;
        }
       
            return rec((i+((j+1)/board[0].size())),(j+1)%board[0].size(),idx,board,word);
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        return rec(0,0,0,board,word);
    }
};