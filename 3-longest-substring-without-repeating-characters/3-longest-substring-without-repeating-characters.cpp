class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>v;
        int ans=0;int sum=0;
        for(int i=0;i<s.size();i++){
            if(v.count(s[i])==0){
                ans++;
                v[s[i]]=i;
            }
            else{
                ans=i-v[s[i]];
               
                for(auto it=v.begin();it!=v.end();){
                    auto it2=it++;
                    if(it2->second<v[s[i]]){
                        
                        v.erase(it2);
                    }
                }
                 v[s[i]]=i;
            }
            // cout<<ans<<endl;
            sum=max(ans,sum);
        }
        return sum;
    }
};