class Solution {
public:
    bool divideString(string &s,string &t){
        // cout<<s<<" "<<t<<endl;
        int n=s.size(),m=t.size();
        if(n%m){
            return false;
        }
        int val=(n/m);
        int i=0;
        bool flag=true;
        // cout<<val<<endl;
        while(i<n&&val){
            // cout<<i<<endl;
            for(int j=0;j<m;j++){
                if(s[i+j]!=t[j]){
                    // cout<<i<<j<<endl;
                    flag=false;
                }
                
            }
            i+=m;
            val--;
        }
        return flag;
    }
    string gcdOfStrings(string str1, string str2) {
        string ans="",t="";
        
        for(int i=0;i<min(str1.size(),str2.size());i++){
            if(str1[i]!=str2[i]){
                break;
            }
            t+=str1[i];
            
            if(divideString(str1,t)&&divideString(str2,t)){
                ans=t;
            }
        }
        return ans;
    }
};