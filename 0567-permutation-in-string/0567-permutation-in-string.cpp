class Solution {
public:
    bool isPalindrome(string &s,string &t){
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            m[t[i]]--;
        }
        for(auto &it:m){
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        
        for(int i=0;i<=n-m;i++){
            string temp=s2.substr(i,m);
            // cout<<temp<<endl;
            if(isPalindrome(s1,temp)){
                return true;
            }
        }
        return false;
    }
};