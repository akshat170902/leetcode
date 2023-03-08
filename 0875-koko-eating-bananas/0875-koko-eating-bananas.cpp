class Solution {
public:
    long long  isCheck(int val,vector<int>&piles){
        long long a=0;
        for(int i=0;i<piles.size();i++){
            a+=ceil(piles[i]/(double)val);
        }
        return a;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long n=piles.size();
        long long low=1,high=(*max_element(piles.begin(),piles.end()))*n;
        while(low<high){
            
            long long mid=low+(high-low)/2;
            long long val=isCheck(mid,piles);
            // cout<<val<<endl;
            if(val<=h){
                high=mid;
            }
            else{
                low=mid+1;
            }
            // cout<<low<<" "<<high<<endl;
        }
        return low;
        
    }
};