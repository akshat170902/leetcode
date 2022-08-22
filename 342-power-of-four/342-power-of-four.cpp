class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n>0){
            int val=log2(n)/2;
            if(val*2==log2(n))
                return true;
            return false;
        }
        return false;
    }
};