class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        vector<int>v;
        sort(p.begin(),p.end());
        for(int i=0;i<s.size();i++){
            long long val=ceil(success/(double)s[i]);
            long long idx=lower_bound(p.begin(),p.end(),val)-p.begin();
            v.push_back(p.size()-idx);
        }
        return v;
    }
};