class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        int i=0;
        while(i<word1.size()||i<word2.size()){
            if(i<word1.size()){
                s+=word1[i];
            }
            if(i<word2.size()){
                s+=word2[i];
            }
            i++;
        }
        return s;
    }
};