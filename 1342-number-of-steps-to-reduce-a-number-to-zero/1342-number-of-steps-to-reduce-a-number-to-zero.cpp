class Solution {
public:
    
    int numberOfSteps(int n) {
        int one =0;
        int zero=0;
        if(n==0){
            return 0;
        }
        int a=log2(n);
         for (int i = a; i >= 0; i--) {
           int k = n >> i;
            if (k & 1)
              one++;
            zero++;
    }
        return zero+one-1;
    }
};