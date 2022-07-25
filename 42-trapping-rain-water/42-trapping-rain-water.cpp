class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>s;
        int res=0;
        for(int i=0;i<height.size();i++){
            while(!s.empty()&&height[i]>height[s.top()]){
                int cur=s.top();
                s.pop();
                if(s.empty())break;
                int dif=i-1-s.top();
                res+=(min(height[i],height[s.top()])-height[cur])*dif;
            }
            s.push(i);
        }
        return res;
    }
};