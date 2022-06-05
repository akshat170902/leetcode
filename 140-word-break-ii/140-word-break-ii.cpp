class Solution {
public:
    void func(int i,string st,string str ,vector<string>&v,string&s,unordered_map<string,int>&m){
        if(i==s.size()-1){
            str+=s[i];
            st+=s[i];
            if(m.count(st)>0){
                v.push_back(str);
            }
            return ;
        }
        st+=s[i];
        str+=s[i];
        // cout<<str<<endl;
        if(m.count(st)>0){
            func(i+1,"",str+" ",v,s,m);
        }
        func(i+1,st,str,v,s,m);
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>v;
        unordered_map<string,int>m;
        string st="",str="";
        for(int i=0;i<wordDict.size();i++){
            m[wordDict[i]]++;
        }
     func(0,st,str,v,s,m);
        return v;
    }
};