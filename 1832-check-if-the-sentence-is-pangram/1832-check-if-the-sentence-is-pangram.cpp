class Solution {
public:
    bool checkIfPangram(string s) {
        if(s.size()<26){
            return false;
        }
        unordered_map<char,bool>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]=true;
        }
        if(m.size()==26){
return true;}return false;
    }
};