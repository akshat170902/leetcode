class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                st.push(s[i]);
            }
            else{
                while(st.size()){
                    ans+=st.top();
                    st.pop();
                }
                ans+=' ';
            }
        }
        while(st.size()){
                ans+=st.top();
                st.pop();
            }
        return ans;
    }
};