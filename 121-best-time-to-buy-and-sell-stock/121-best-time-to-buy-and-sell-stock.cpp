class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low=INT_MAX,ans=0;
        for(int i=0;i<prices.size();i++){
            low=min(low,prices[i]);
            ans=max(prices[i]-low,ans);
        }
        return ans;
    }
};