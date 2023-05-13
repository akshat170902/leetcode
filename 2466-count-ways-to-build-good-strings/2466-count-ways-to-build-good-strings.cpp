class Solution {
    unordered_map<long long,long long>m;
    int mod=1e9+7;
public:
    int rec(int len,int zero ,int one){
        if(len<0){
            return 0;
        }
        if(len==0){
            return 1;
        }
        if(m.count(len)){
            return m[len];
        }
        long long val1=rec(len-zero,zero,one);
        long long val2=rec(len-one,zero,one);
        
        return m[len]=(val1+val2)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        long long ans=0;
        for(int i=low;i<=high;i++){
            ans=(ans+rec(i,zero,one))%mod;
        }
        return ans;
    }
};