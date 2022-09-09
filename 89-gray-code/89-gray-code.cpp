class Solution {
public:
    vector<int> grayCode(int m) {
        vector<int>ans={0,1};
        for(int i=2;i<=m;i++){
            int n=ans.size();
            for(int j=n-1;j>=0;j--){
                ans.push_back(ans[j]+n);
            }
        }
        return ans;
    }
};