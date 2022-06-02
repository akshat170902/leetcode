class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        vector<int>cur(n+1),prev(n+1);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j]=='1'){
                cur[j]=min(prev[j],min(prev[j+1],cur[j+1]))+1;
                }
                else{
                    cur[j]=0;
                }
                // cout<<cur[j]<<" ";
                ans=max(cur[j],ans);
            }
            // cout<<endl;
            prev=cur;
        }
        return ans*ans;
    }
};