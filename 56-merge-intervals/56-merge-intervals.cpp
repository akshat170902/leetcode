class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int prev=-1;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(prev<intervals[i][0]){
                if(prev!=-1)
                ans[ans.size()-1].push_back(prev);
                vector<int>temp;
                temp.push_back(intervals[i][0]);
                ans.push_back(temp);
                prev=max(prev,intervals[i][1]);
                }
            else{
                prev=max(prev,intervals[i][1]);
            }
        }
        ans[ans.size()-1].push_back(prev);
        return ans;
    }
};