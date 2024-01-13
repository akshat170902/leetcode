class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>m,n;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            n[t[i]]++;
        }
        int sum=0;
        for(auto it=m.begin();it!=m.end();it++){
            sum+=max(it->second-n[it->first],0);
        }
        return sum;
    }
};