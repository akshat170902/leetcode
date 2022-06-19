class StockSpanner {
    vector<pair<int,int>>dp;
    
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int j=1;
        // cout<<price<<endl;
        for(int i=dp.size()-1;i>=0;i--){
            if(dp[i].first<=price){
               
                j+=dp[i].second;
                 i=i-dp[i].second+1;
                // cout<<dp[i].second<<" "<<price<<endl;
            }
            else{
                break;
            }
        }
        dp.push_back({price,j});
        return j;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */