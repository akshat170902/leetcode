class Solution {
public:
    double myPow(double x, int n) {
        if(n==1){
            return x;
        }
        if(n==0){
            return 1.0;
        }
        if(n==-1){
            return 1/x;
        }
        double val{};
        if(n%2){
            val=myPow(x,(n-1)/2);
        }
        else{
            val=myPow(x,n/2);
        }
        return n%2?val*val*x:val*val;
    }
};