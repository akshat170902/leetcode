class Solution {
public:
    bool isSafe(int x1,int y1,int x2,int y2,int r){
        return r*r>=pow(x1-x2,2)+pow(y1-y2,2);
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
           int val=0;
           for(int j=0;j<points.size();j++){
             if(isSafe(points[j][0],points[j][1],queries[i][0],queries[i][1],queries[i][2])){
                    val++;
                }
            }
            ans.push_back(val);
        }
        return ans;
    }
};