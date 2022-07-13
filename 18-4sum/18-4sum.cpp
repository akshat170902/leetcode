class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){                
            if(i!=0&&nums[i]==nums[i-1])continue;
            for(int j=i+1;j<nums.size();j++){
                if(j!=i+1&&nums[j]==nums[j-1])continue;
                long long int tar=(long long int)target-nums[i]-nums[j];
                int right=nums.size()-1,left=j+1;
                while(left<right){
                    if(left!=j+1&&nums[left]==nums[left-1])left++;
                    else if(right!=nums.size()-1&&nums[right]==nums[right+1])right--;
                    else if(nums[left]+nums[right]<tar){
                        left++;
                    }
                    else if(nums[left]+nums[right]>tar){
                        right--;
                    }
                    else{
                        // cout<<j<<endl;
                        vector<int>v={nums[i],nums[j],nums[left],nums[right]};
                        ans.push_back(v);
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};