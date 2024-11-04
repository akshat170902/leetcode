class Solution {
public:
    string compressedString(string word) {
        int n=word.size();
        string res="";
        for(int i=0;i<n;){
            int cur=0;
            char ch=word[i];
            while(i<n&&word[i]==ch&&cur!=9){
                cur++;
                i++;
            }
            res+=cur+'0';
            res+=ch;
        }
        return res;
    }
};