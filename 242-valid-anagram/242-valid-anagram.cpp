class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size(),m=t.size();
        
        if(n!=m){
            return false;
        }
        
        int salph[26]={0},talph[26]={0};
        for(int i=0;i<n;i++){
            salph[s[i]-'a']++;
            talph[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(salph[i]!=talph[i]){
                return false;
            }
        }
        return true;
    }
};