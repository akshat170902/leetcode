class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n=s.size();
        sort(s.begin(),s.end());
        vector<vector<string>>v;
        unordered_map<string,vector<string>>ans;
        // vector<vector<int>>v;
        for(int i=0;i<n;i++){
            string temp=s[i];
            sort(temp.begin(),temp.end());
            ans[temp].push_back(s[i]);
        }
        for(auto it:ans){
            v.push_back(it.second);
        }
        return v;
    }
};