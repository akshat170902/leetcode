class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int>ans;
        bool flag=true,revers=false;
        int rowStart=0,rowEnd=n-1,columnStart=0,columnEnd=m-1;
        while(rowStart<=rowEnd&&columnStart<=columnEnd){
            if(flag){
                if(revers){
                    for(int i=columnEnd;i>=columnStart;i--){
                        
                        ans.push_back(matrix[rowEnd][i]);
                    }
                    rowEnd--;
                    flag=false;
                }
                else{
                    for(int i=columnStart;i<=columnEnd;i++){
                        // cout<<matrix[rowStart][i]<<endl;
                        ans.push_back(matrix[rowStart][i]);
                    }
                    rowStart++;
                    flag=false;
                }
            }
            else{
                if(revers){
                    for(int i=rowEnd;i>=rowStart;i--){
                        // cout<<matrix[i][columnStart]<<endl;
                        ans.push_back(matrix[i][columnStart]);
                    }
                    columnStart++;
                    revers=false;
                    flag=true;
                }
                else{
                    for(int i=rowStart;i<=rowEnd;i++){
                        // cout<<matrix[i][columnEnd]<<endl;
                        ans.push_back(matrix[i][columnEnd]);
                    }
                    columnEnd--;
                    revers=true;
                    flag=true;
                }
            }
            
            
        }
        return ans;
    }
};