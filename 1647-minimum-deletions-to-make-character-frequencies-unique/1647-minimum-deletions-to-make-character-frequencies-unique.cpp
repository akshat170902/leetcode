class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>ml;
        vector<int>prev;
        unordered_map<int,int>m;
        int ans=0;
        int large=0;
        for(int i=0;i<s.size();i++){
            ml[s[i]]++;
            large=max(large,ml[s[i]]);
        }
        
        for(auto it=ml.begin();it!=ml.end();it++){
            m[it->second]++;
        }
        
        for(int i=1;i<large+1;i++){
            if(m.count(i)==0){
                prev.push_back(i);
            }
            else if(m[i]==1){
                continue;
            }
            else{
                while (m[i]!=1){
                    int last=0;
                    if(prev.size()>0){
                        last=prev.back();
                        prev.pop_back();
                    }
                    ans+=i-last;
                    m[i]--;
                }
            }
        }
        return ans;
    }
};