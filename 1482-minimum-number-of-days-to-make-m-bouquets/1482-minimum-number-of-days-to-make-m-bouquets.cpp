class Solution {
public:
    bool check(vector<int>&v,int val,int m,int k){
        int curr=0;
        for(int i=0;i<v.size();i++){
           int count=0;
           while(i<v.size()&&v[i]<=val){
               count++;
               i++;
           }
           curr+=count/k;
           
       } 
        if(curr>=m){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, long long m, int k) {
        int l=0,h=1e9;
        if(m*k>(long long)bloomDay.size()){
            return -1;
        }
        // cout<<h<<endl;
        while(l<h){
            int mid=l+(h-l)/2;
            // cout<<l<<" "<<h<<endl;
            if(check(bloomDay,mid,m,k)){
                h=mid;
            }
            else{
                l=mid+1;
            }
        }
        return h;
    }
};