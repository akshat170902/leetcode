class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a=0;
        int b=0;
        for(int i=2;i<=cost.size();i++){
            int c=min(a+cost[i-1],b+cost[i-2]);
            b=a;
            a=c;
        }
        return a;
    }
};