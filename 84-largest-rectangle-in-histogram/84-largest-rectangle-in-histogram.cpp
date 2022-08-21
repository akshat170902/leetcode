class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n=height.size();
        int left[n],right[n];
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty()&&height[s.top()]>=height[i]){
                s.pop();
            }
            if(s.empty()){
                left[i]=0;
            }
            else{
                left[i]=s.top()+1;
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&height[s.top()]>=height[i]){
                s.pop();
            }
            if(s.empty()){
                right[i]=n;
            }
            else{
                right[i]=s.top();
            }
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(right[i]-left[i])*height[i]);
        }
        return ans;
    }
};