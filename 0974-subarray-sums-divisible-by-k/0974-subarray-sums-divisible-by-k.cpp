class Solution {
public:
    int negMod(int n,int mod){
        
        if(n<0){
            n=abs(n)%mod;
            return (-n+mod)%mod;
        }
        
        return n%mod;
    }
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        
        int cur=0,ans=0;
        unordered_map<int,int>m;
        m[0]++;
        
        for(int num:nums){
            
            cur=(cur+negMod(num,k))%k;
            
            if(m.count(cur)){
                ans+=m[cur];
                
            }
            m[cur]++;
        }
        return ans;
    }
};