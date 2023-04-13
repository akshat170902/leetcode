class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int j=0;
        
        for(int i=0;i<pushed.size();i++){
            st.push(pushed[i]);
            while(st.size()&&j<popped.size()&&st.top()==popped[j]){
                j++;
                st.pop();
            }
            
        }
        if(st.size()||j!=popped.size()){
            return false;
        }
        return true;
    }
};