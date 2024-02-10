class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {

    int n=arr.size();
//     cout<<"a"<<endl;
    sort(begin(arr),end(arr));
    vector<int>dp(n),hash(n);
    int idx=0;
    int maxin=INT_MIN;
    for(int i=0;i<n;i++)hash[i]=i;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]%arr[j]==0&&dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                hash[i]=j;
            }
            if(dp[i]>maxin){
                idx=i;
                maxin=dp[i];
            }
            
        }
    }
        vector<int>ans;
        while(hash[idx]!=idx){
//             cout<<arr[idx]<<endl;
            ans.push_back(arr[idx]);
            idx=hash[idx];
        }
    ans.push_back(arr[idx]);
        reverse(ans.begin(),ans.end());
        return ans;
    
}
    
};