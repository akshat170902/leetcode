class Solution {
public:
    long long isSafe(vector<int>&time,long long val){
        long long a=0;
        for(int i=0;i<time.size();i++){
            a+=val/time[i];
        }
        return a;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low=1,high=1e14;
        
        while(low<high){
            long long mid=low+(high-low)/2;
            
            if(isSafe(time,mid)>=totalTrips){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};