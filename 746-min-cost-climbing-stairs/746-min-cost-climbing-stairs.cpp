class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int cur=0,curNext=0,curNextNext=0;
        for(int idx=cost.size()-1;idx>=0;idx--){
            cur=min(curNext,curNextNext)+cost[idx];
            curNextNext=curNext;
            curNext=cur;
        }
        return min(curNext,curNextNext);
    }
};