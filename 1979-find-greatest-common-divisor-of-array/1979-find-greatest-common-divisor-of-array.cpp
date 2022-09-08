class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxVal=INT_MIN,minVal=INT_MAX;
        for(int num:nums){
           if(num>maxVal){
               maxVal=num;
           }
           if(num<minVal){
               minVal=num;
           }
            
        }
        return __gcd(minVal,maxVal);
        
    }
};