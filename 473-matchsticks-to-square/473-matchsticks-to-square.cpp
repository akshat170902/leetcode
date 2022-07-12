class Solution {
    bool helper(int cur, int tar, int cnt, int k, int mask, vector<int>& s, vector<int>& dp)
    {
        if (cnt == k)
            return true;
        if (dp[mask] != -1) return dp[mask];
        int n = s.size();
        bool res = false;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1<<i)) continue;
            if (cur+s[i] > tar) break;
            if (cur+s[i] == tar)
            {
                mask^=1<<i;
                res |= helper(0, tar, cnt+1, k, mask, s, dp);
                mask^=1<<i;
            }
            else
            {
                mask^=1<<i;
                res |= helper(cur+s[i], tar, cnt, k, mask, s, dp);
                mask^=1<<i;
            }
            if (res) break;
        }
        dp[mask] = res?1:0;
        return res;
    }
public:
    bool makesquare(vector<int>& s) {
        int sum = 0, n = s.size();
        for (int i:s) sum+=i;
        if (sum%4 != 0) return false;
        sum/=4;
        sort(s.begin(), s.end());
        vector<int> dp(1<<n, -1);
        return helper(0, sum, 0, 4, 0, s, dp);
    }
};