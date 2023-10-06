class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int val1,count1=0;
        int val2=-1e9-1,count2=0;
        for(int i=0;i<n;i++){
            
            if(nums[i]==val1){
                count1++;
            }
            else if(nums[i]==val2){
                count2++;
            }
            else if(count1==0){
                val1=nums[i];
                count1=1;
            }
            else if(count2==0){
                val2=nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
                
            }
        }
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==val1){
                c1++;
            }
            if(nums[i]==val2){
                c2++;
            }
            
        }
        if(c1>n/3){
            ans.push_back(val1);
        }
        if(c2>n/3){
            ans.push_back(val2);
        }
        return ans;
    }
};