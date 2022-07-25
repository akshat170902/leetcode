class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            // cout<<nums[i]<<endl;
            if(i!=0&&nums[i]==nums[i-1]){
                    
                    continue;
                }
            
            int tar=-1*nums[i];
            int left=i+1,right=n-1;
            
            while(left<right){
                // cout<<left<<right<<endl;
                if(left!=i+1&&nums[left]==nums[left-1]){
                    left++;
                    continue;
                }
                else if(right!=n-1&&nums[right]==nums[right+1]){
                    right--;
                    continue;
                }
                else{
                    if(nums[left]+nums[right]==tar){
                        vector<int>v;
                        v.push_back(nums[i]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        ans.push_back(v);
                        left++;
                        right--;
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
        return ans;
    }
};