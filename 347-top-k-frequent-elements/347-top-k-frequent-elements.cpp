class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        vector<int>ans;
        map<int,vector<int>>u;
        for(auto num:nums){
            m[num]++;
        }
        for(auto val:m){
            u[val.second].push_back(val.first);
        }
        for(auto it=u.rbegin();it!=u.rend();it++){
            for(int val:it->second){
                if(k==0){
                    return ans;
                }
                else{
                    ans.push_back(val);
                    k--;
                }
            }
        }
        return ans;
    }
};