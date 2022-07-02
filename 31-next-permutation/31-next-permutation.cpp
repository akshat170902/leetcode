class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(i==0)n=-1;
            else{
                if(nums[i]>nums[i-1]){
                    n=i-1;
                    break;
                }
            }
        }
        int i=nums.size()-1;
        // cout<<n<<" "<<i<<endl;
        if(n!=-1){
        while(nums[n]>=nums[i]){
            i--;
        }
        
        swap(nums[n],nums[i]);
        }
        sort(nums.begin()+1+n,nums.end());
        
    }
};