class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        long long sum=0,mini=LONG_MAX;
        int neg=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=abs(matrix[i][j]);
                mini=min((long long)abs(matrix[i][j]),mini);
                if(matrix[i][j]<0){
                    neg=(neg+1)%2;
                }
                // cout<<sum<<mini<<neg<<endl;
            }
        }
        return !neg?sum:sum-mini*2;
    }
};