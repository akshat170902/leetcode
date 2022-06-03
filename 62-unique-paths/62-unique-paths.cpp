class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m>n)swap(n,m);
        m--;n--;
            double ans=1.0;
        long long int a=1,b=1;
        for(int i=0;i<m;i++){
            ans=ans*((double)(n+m-i))/((double)(i+1));
        }
         
        return ans;
        
    }
};