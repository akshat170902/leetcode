class Solution {
public:
    bool isPalindrome(string S)
{ 
    for (int i = 0; i < S.length() / 2; i++) {
  
        if (S[i] != S[S.length() - i - 1]) {
           
            return false;
        }
    }
    
    return true;
}
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            string cur="";

            for(int j=i;j<s.size();j++){
                cur+=s[j];
                if(isPalindrome(cur)){
                    ans ++;
                }
            }
        }
        return ans;
    }
};