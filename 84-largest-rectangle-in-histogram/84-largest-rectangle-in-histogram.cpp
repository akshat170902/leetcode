class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n=heights.size();
        stack<int>s;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!s.empty()&&heights[s.top()]>heights[i]){
                int val=s.top();
                s.pop();
                if(s.empty())
                    ans=max(ans,(i)*heights[val]);
                else
                    ans=max(ans,(i-s.top()-1)*heights[val]);
            }
            s.push(i);
        }
        heights.pop_back();
        return ans;
    }
};