class Solution {
public:
    bool judgeSquareSum(int c) {
        int upperLimit=sqrt(c/2);
        for(int i=0;i<=upperLimit;i++){
            int temp=sqrt(c-i*i);
            if(temp*temp+i*i==c){
                return true;
            }
            
        }
        return false;
    }
};