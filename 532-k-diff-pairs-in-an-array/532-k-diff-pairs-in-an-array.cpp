class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int val:nums)m[val]++;
        int ans=0;
        for(auto it:m){
            if(k!=0&&m.count(it.first+k)){
                // cout<<it.first+k<<endl;
                ans++;
            }
            else if(k==0){
                if(it.second>1){
                    ans++;
                }
            }
        }
        return ans;
    }
};