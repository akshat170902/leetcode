class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        vector<int>cur(2,0),prev(2,0);
        for(int idx=prices.size()-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
        int take=0,notTake=0;
        if(buy){
            take=prev[0]-prices[idx];
            notTake=prev[1];
        }
        else{
            take=prices[idx];
            notTake=prev[0];
        }
        cur[buy]= max(take,notTake);
            }
            prev=cur;
        }
        return cur[1];
    }
};