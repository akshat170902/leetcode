class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int result=0,prev=0;
        unordered_map<int,int>m;
        m[0]++;
        for(auto&num:nums){
            int val=((num+prev)%k+k)%k;
            prev=val;
            result+=m[val];
            m[val]++;
        }
        return result;
    }
};