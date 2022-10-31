class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& m) {
        int n=m.size(),l=m[0].size();
        
        for(int i=0;i<l;i++){
            int val=m[0][i];
            for(int j=0;j<min(l-i,n);j++){
                if(m[j][i+j]!=val){
                    // cout<<i<<j<<endl;
                    return false;
                }
            }
        }
        for(int i=0;i<n;i++){
            int val=m[i][0];
            for(int j=0;j<min(n-i,l);j++){
                if(m[i+j][j]!=val){
                    return false;
                }
            }
        }
        return true;
    }
};