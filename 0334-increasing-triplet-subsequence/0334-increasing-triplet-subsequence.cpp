class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            if(v.size()==0||lower_bound(v.begin(),v.end(),nums[i])==v.end()){
                v.push_back(nums[i]);
            }
            else{
                v[lower_bound(v.begin(),v.end(),nums[i])-v.begin()]=nums[i];
                
            }
        }
        return v.size()>=3;


    }
};