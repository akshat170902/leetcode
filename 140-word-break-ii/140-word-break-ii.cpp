class Solution {
public:
    vector<string>rec(int idx,string &s,unordered_map<string,bool>&m){
    int n=s.size();
    vector<string>ans;
    if(idx==s.size()){
        ans.push_back("");
        return ans;
    }
    for(int i=1;i+idx<=n;i++){
        string temp=s.substr(idx,i);
        if(m.count(temp)>0){
            vector<string>res=rec(idx+i,s,m);
            if(idx+i!=n)
                for(int j=0;j<res.size();j++)
                    ans.push_back(temp+" "+res[j]);
            else
                for(int j=0;j<res.size();j++)
                    ans.push_back(temp+res[j]);
            
        }
    }
    return ans;
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    
    unordered_map<string,bool>m;
    for(int i=0;i<dictionary.size();i++){
        m[dictionary[i]]=true;
    }
    return rec(0,s,m);

}
};