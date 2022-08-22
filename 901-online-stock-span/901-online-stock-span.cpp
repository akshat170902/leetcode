class StockSpanner {
    stack<pair<int,int>>s;
    
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans=1;
        while(!s.empty()&&(s.top().first<=price)){
                ans+=s.top().second;
                s.pop();
            }
        s.push({price,ans});
        return ans;
    }
};
