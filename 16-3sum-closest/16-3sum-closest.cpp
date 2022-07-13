class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int prev=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int tar=target-nums[i];
            int left=i+1,right=nums.size()-1;
            while(left<right){
                if(abs(prev)>abs(tar-nums[left]-nums[right])){
                    prev=tar-nums[left]-nums[right];
                }
                if(nums[left]+nums[right]==tar){
                    return target;
                }
                else if(nums[left]+nums[right]<tar){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return target-prev;
    }
};