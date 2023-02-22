class Solution {
public:
    bool isSafe(vector<int>&w,int d,int val){
        int n=w.size();
        int ans=0;
        int cur=0;
        int prev=-1;
        while(1){
            int idx=upper_bound(w.begin(),w.end(),val+cur)-w.begin()-1;
            if(idx<=prev){
                return false;
            }
            cur=w[idx];
            prev=idx;
            
            ans++;
            if(idx==n-1){
                break;
            }
        }
        return ans<=d;
    }
    int shipWithinDays(vector<int>&w, int d) {
        for(int i=1;i<w.size();i++){
            w[i]+=w[i-1];
        }
        int low=0,high=w.back();
        while(low<high){
            // cout<<low<<" "<<high<<endl;
            int mid=low+(high-low)/2;
            // cout<<mid<<endl;
            if(isSafe(w,d,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return high;
    }
};