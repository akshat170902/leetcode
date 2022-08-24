class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n<=0)return false;
        if(n==1)return true;
        int val=log10(n)/log10(3);
        return pow(3,val)==n;
    }
};