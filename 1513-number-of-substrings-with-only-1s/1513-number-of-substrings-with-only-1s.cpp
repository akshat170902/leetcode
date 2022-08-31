class Solution {
public:
    int numSub(string s) {
        int low=0,high=0;
        int ans=0;
        int mod=1e9+7;
        while(low<s.size()&&high<s.size()&&low<=high){
            while(s[high]=='0'){
                high++;
                low=high;
                
            }
            while(s[high]=='1'){
                high++;
                ans=(ans+(high-low)%mod)%mod;
            }
        }
        return ans%mod;
    }
};