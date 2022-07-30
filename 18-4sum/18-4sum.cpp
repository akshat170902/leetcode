class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i==0||nums[i]!=nums[i-1]){
                for(int j=i+1;j<n;j++){
                    if(j==i+1||nums[j]!=nums[j-1]){
                        long long tar=(long long)target-nums[i]-nums[j];
                        int right=n-1,left=j+1;
                        while(left<right){
                            if(left!=j+1&&nums[left]==nums[left-1]){
                                left++;
                                continue;
                            }
                            if(right!=n-1&&nums[right]==nums[right+1]){
                                right--;
                                continue;
                            }
                            if(nums[left]+nums[right]==tar){
                                vector<int>temp={nums[i],nums[j],nums[left],nums[right]};
                                ans.push_back(temp);
                                left++;
                            }
                            else if(nums[left]+nums[right]<tar){
                                left++;
                            }
                            else{
                                right--;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};