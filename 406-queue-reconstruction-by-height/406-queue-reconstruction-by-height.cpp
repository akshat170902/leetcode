class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>>dp(people.size(),vector<int>(people[0].size(),-1));
        sort(people.begin(),people.end());
        int start=0;
        for(int i=0;i<people.size();i++){
            int count =0,idx=0;
            
            int num=people[i][1];
            for(int j=0;j<people.size()&&count<=num;j++){
                if(dp[j][0]==-1||dp[j][0]==people[i][0])count++;
                idx=j;
            }
            dp[idx]=people[i];
        }
        return dp;
    }
};