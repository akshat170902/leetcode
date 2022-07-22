class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>result;
        
        sort(intervals.begin(),intervals.end());
        int prev=intervals[0][0],last=intervals[0][1];
        for(int i=1;i<n;i++){
            if(last>=intervals[i][0]){
                last=max(last,intervals[i][1]);
                
                prev=min(prev,intervals[i][0]);
                
            }
            else{
                vector<int>v;
                v.push_back(prev);
                v.push_back(last);
                result.push_back(v);
                prev=intervals[i][0],last=intervals[i][1];
            }
        }
        vector<int>v;
        v.push_back(prev);
        v.push_back(last);
        result.push_back(v);
        return result;
    }
};