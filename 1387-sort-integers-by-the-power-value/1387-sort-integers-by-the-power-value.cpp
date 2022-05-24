vector<int>dp(4001);
class Solution {
public:
    int powers(int n){
        if(n<4000){
        if(n==1){
            return 0;
        }
        if(dp[n]){
            return dp[n];
        }
        else{
              
            if(n%2==1){
               
                dp[n]=powers(3*n+1)+1;
                return dp[n];
            }
            else{
                dp[n]=powers(n/2)+1;
                return dp[n];
            }
        }}
       else{
           if(n%2==1){
               
              return  powers(3*n+1)+1;
                  
            }
            else{
               return powers(n/2)+1;
                
            }
       }
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>v;
         
 
        for(int i=lo;i<hi+1;i++){
           v.push_back({powers(i),i});
        }
        sort(begin(v),end(v));
        return v[k-1].second;
    }
};