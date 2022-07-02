class Solution {
public:
    int maxArea(int h, int w, vector<int>& H, vector<int>& V) {
        sort(H.begin(),H.end());
        sort(V.begin(),V.end());
        
        H.push_back(h);
        V.push_back(w);
        
        int L=0,B=0,mod=1e9+7;
        
        for(int i=0;i<H.size();i++){
           
            L=i==0?max(L,H[i]):max(L,H[i]-H[i-1]);
        }
        for(int i=0;i<V.size();i++){
            B=i==0?max(B,V[i]):max(B,V[i]-V[i-1]);
        }
        long long int l=L,b=B;
        
        
        long long int ans=(l*b)%mod;
        return ans;
    }
};