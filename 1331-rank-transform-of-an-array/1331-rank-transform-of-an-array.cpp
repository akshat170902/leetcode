class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        int val=1;
        for(auto&it:m){
            // cout<<it.first<<' '<<val<<endl;
            it.second=val++;
            // cout<<it.second<<endl;
        }
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++){
            // cout<<arr[i]<<" "<<m[arr[i]]<<endl;
            ans[i]=m[arr[i]];
        }
        return ans;
    }
};