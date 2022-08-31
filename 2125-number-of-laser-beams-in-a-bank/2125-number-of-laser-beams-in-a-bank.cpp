class Solution {
public:
    int oneCount(string &s){
        int one=0;
        for(int i=0;i<s.size();i++)
            if(s[i]=='1')one++;
        return one;
    }
    int numberOfBeams(vector<string>& bank) {
        stack<int>st;
        for(string s:bank){
            int val=oneCount(s);
            if(val!=0)
                st.push(val);
        }
        int ans=0;
        if(st.empty()){
            return ans;
        }
        int val=st.top();
        
        st.pop();
        while(st.size()){
            // cout<<val<<endl;
            ans+=st.top()*val;
            val=st.top();
            st.pop();
        }
        return ans;
    }
};