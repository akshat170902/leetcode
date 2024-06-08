class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            nums[i]=(nums[i]+(i>0?nums[i-1]:0))%k;
            
            
            if(i>0){
                m[sum]++;
                sum=nums[i-1];
            }
            if(m.count(nums[i])){
                return true;
            }
        }
        return false;
    }
};