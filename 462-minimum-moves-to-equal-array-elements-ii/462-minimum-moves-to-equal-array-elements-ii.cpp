class Solution {
public:
    int minMoves2(vector<int>& a) {
        int n=a.size(),ans=0;
        sort(a.begin(), a.end());
 int median=0;
    if (n % 2 != 0)
        median=a[n / 2];
 else
    median=(a[(n - 1) / 2] + a[n / 2]) / 2;
        for(int i=0;i<n;i++){
            ans+=abs(median-a[i]);
        }
        return ans;
    }
};