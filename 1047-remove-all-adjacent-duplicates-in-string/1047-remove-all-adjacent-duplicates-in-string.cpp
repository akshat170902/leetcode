class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
       for(int i=0;i<s.size();i++){
           if(st.empty()||st.top()!=s[i]){
               st.push(s[i]);
           }
           else if(st.top()==s[i]){
               st.pop();
           }
       } 
        string res="";
    while(!st.empty()){
        res=st.top()+res;
        st.pop();
    }
        return res;
    }
};