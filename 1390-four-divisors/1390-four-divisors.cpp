class Solution {
public:
    pair<int,int> numberOfDivisors(int n){
        int val=0;
        int sum=0;
        int sqrtN=sqrt(n);
        if(sqrtN*sqrtN==n){
            val--;
            sum-=sqrtN;
        }
        for(int i=1;i<=sqrtN;i++){
            if(n%i==0){
                val+=2;
                sum+=(i+(n/i));
            }
        }
        
        return {val,sum};
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            auto p=numberOfDivisors(nums[i]);
            // cout<<nums[i]<<" "<<p.first<<endl;
            if(p.first==4){
                
                sum+=p.second;
            }
        }
        return sum;
    }
};