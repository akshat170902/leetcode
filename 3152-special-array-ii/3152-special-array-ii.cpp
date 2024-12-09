class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>v(n,0);
        v[0]=1;
        for(int i=1;i<n;i++){
            v[i]=((nums[i]%2)!=(nums[i-1]%2))+v[i-1];
        }
        vector<bool>ans;
        for(auto&q:queries){
            if(q[1]-q[0]==v[q[1]]-v[q[0]]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};