class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size(),m=str2.size(),idx=0;
        for(int i=0;i<n&&idx<m;i++){
            if((((str1[i]-'a'+1)%26)+'a')==str2[idx] || str1[i]== str2[idx]){
                idx++;
            }
        }
        return idx==m;
    }
};