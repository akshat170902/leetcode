class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;
        n--;
        if(m<n){
            swap(n,m);
        }
        long long int p=1;
        long long int q=1;
        for(int i=0;i<m;i++){
            p*=(n+m-i);
            q*=(m-i);
            int gcd=__gcd(p,q);
            p/=gcd;
            q/=gcd;
        }
        return p/q;
    }
};