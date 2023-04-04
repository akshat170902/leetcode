class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        unordered_map<char,int>m;
        int ans=1;
        for(int i=0;i<n;i++){
            if(m.count(s[i])){
                ans++;
                m.clear();
            }
            m[s[i]]=i;
        }
        return ans;
    }
};