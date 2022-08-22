class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++){
            if(s[i]==' ')
                continue;
            string temp="";
            while(i<n&&s[i]!=' '){
                temp+=s[i];
                i++;
            }
            if(res==""){
                res=temp;
            }
            else
                res=temp+" "+res;
        }
        return res;
    }
};