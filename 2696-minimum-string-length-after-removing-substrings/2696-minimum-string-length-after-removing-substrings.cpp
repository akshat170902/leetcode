class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        int i=0,n=s.size();
        st.push(s[i]);
        i++;
        while(i<n){
            
            cout<<st.size()<<endl;
            if((st.size()>0)&&((s[i]=='B'&&st.top()=='A')||(s[i]=='D'&&st.top()=='C'))){
                
                st.pop();
                // cout<<s[i]<<st.size()<<endl;
            }
            else{
                // cout<<s[i]<<endl;
                st.push(s[i]);
            }
           i++;
        }
        // cout<<st.size();
        return st.size();
    }
};