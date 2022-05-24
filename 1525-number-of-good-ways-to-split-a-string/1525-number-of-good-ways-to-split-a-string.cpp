class Solution {
public:
    int numSplits(string s) {
        vector<int>a,b;
        int ans=0;
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            a.push_back(m.size());
        }
        m.clear();
        for(int i=s.size()-1;i>=0;i--){
            m[s[i]]++;
            b.push_back(m.size());
        }
        int n=s.size();
        for(int i=0;i<n-1;i++){
            cout<<a[i]<<b[n-i-2]<<endl;
            if(a[i]==b[n-i-2]){
                ans++;
                cout<<i<<endl;
            }
        }
        return ans;
    }
};