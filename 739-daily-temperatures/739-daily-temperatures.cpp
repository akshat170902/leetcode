class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tes) {
        vector<int>dp(tes.size());
        stack<int>s;
        s.push(0);
        for(int i=1;i<tes.size();i++){
            if(tes[i]>tes[s.top()]){
                while(!s.empty()&&tes[i]>tes[s.top()]){
                   dp[s.top()]=i-s.top();
                    s.pop();
                }
            }
            s.push(i);
        }
        while(!s.empty()){
            dp[s.top()]=0;
            s.pop();
        }
        return dp;
    }
};