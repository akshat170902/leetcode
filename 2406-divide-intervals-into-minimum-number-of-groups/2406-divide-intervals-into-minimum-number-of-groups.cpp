class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        unordered_map<int,int>m;
        for(int i=0;i<intervals.size();i++){
            m[intervals[i][0]]++;
            m[intervals[i][1]+1]--;
            
        }
        int ans=1;
        int cur=0;
        for(int i=1;i<=1000000;i++){
            // cout<<m[i]<<endl;
            cur+=m.count(i)?m[i]:0;
            ans=max(ans,cur);
        }
        return ans;
    }
};