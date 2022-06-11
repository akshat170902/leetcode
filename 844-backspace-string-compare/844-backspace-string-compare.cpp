class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string sr="",st="";
        
        int j=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='#'){
                j++;
            }
            else if(j!=0){
                
                j--;
            }
            else{
                sr=s[i]+sr;
            }
        }
    j=0;
        for(int i=t.size()-1;i>=0;i--){
            if(t[i]=='#'){
                j++;
            }
            else if(j>0){
               j--;
            }
            else{
                st=t[i]+st;
            }
            cout<<st<<endl;
        }
        if(sr==st)return true;
        return false;
    }
};