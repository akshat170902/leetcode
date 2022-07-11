class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=0;
        while(i<nums.size()&&nums[i]<0){
            i++;
        }
        j=i-1;
        vector<int>ans;
        while(j!=-1||i!=nums.size()){
            // cout<<i<<" "<<j<<endl;
            if(j==-1){
             ans.push_back(nums[i]*nums[i]);
                i++;
            }
            else if(i==nums.size()){
                ans.push_back(nums[j]*nums[j]);
                j--;
            }
            else{
               if(nums[i]<abs(nums[j])){
                ans.push_back(nums[i]*nums[i]);
                i++;
            }
            else{
                ans.push_back(nums[j]*nums[j]);
                j--;
                }
            }
        }
        return ans;
    }
};