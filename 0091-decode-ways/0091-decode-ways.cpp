class Solution {
public:
    string s;
    int n;
    vector<int> dp;
    int f(int i){
        if (i==n) return 1;
        if (dp[i]!=-1) return dp[i];
        if (s[i]=='0') return dp[i]=0;
        int ans=f(i+1);
        if ( i+1<n && (s[i]=='1'|| (s[i]=='2' && s[i+1]<='6'))){
            ans+=f(i+2);
        }
        return dp[i]=ans;
    }
    int numDecodings(string& s) {
        if (s[0]=='0') return 0;
        int n=s.size();
        dp.assign(3, 0);
        dp[n%3]=1;
        for (int i=n-1; i>=0; i--){
            if (s[i]=='0') dp[i%3]=0;
            else{
                 dp[i%3]=dp[(i+1)%3];
                 if (i+1<n && (s[i]=='1'|| (s[i]=='2' && s[i+1]<='6')))
                    dp[i%3]+=dp[(i+2)%3];
            }
        }
        return dp[0];
    }
};
