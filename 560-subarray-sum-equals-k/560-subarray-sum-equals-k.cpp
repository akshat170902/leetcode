class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int>m;
        int ans=0;
        m[0]++;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
            if(m.count(sum-k)>0){
                ans+=m[sum-k];
            }
            m[sum]++;
        }
        
        return ans;
    }
};