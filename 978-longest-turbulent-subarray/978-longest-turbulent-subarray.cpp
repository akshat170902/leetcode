class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
       int sum=1;
       int ans=1;
       bool flag=nums[0]<nums[1];
       for(int i=0;i<nums.size()-1;){
           // cout<<i<<endl;
        if(flag){
            if(i%2==0){
                if(nums[i]<nums[i+1]){
                    sum++;
                    ans=max(ans,sum);
                    i++;
                }
                else if(nums[i]==nums[i+1]){
                    i++;
                    sum=1;
                }
                else{
                    sum=1;
                    flag=false;
                }
            }
            else{
                if(nums[i]>nums[i+1]){
                    sum++;
                    ans=max(ans,sum);
                    i++;
                }
                else if(nums[i]==nums[i+1]){
                    i++;
                    sum=1;
                }
                else{
                    sum=1;
                    flag=false;
                }
            }
        }
        else{
            if(i%2==0){
                if(nums[i]>nums[i+1]){
                    sum++;
                    ans=max(ans,sum);
                    i++;
                }
                else if(nums[i]==nums[i+1]){
                    i++;
                    sum=1;
                }
                else{
                    sum=1;
                    flag=true;
                }
            }
            else{
                if(nums[i]<nums[i+1]){
                    sum++;
                    ans=max(ans,sum);
                    i++;
                }
                else if(nums[i]==nums[i+1]){
                    i++;
                    sum=1;
                }
                else{
                    sum=1;
                    flag=true;
                }
            }
        }
       }
       return ans; 
    }
};