class Solution {
public:
    bool divideString(string &s,string &t){
        
        int n=s.size(),m=t.size();
        if(n%m){
            return false;
        }
        int val=(n/m);
        int i=0;
        bool flag=true;
        
        while(i<n&&val){
            
            for(int j=0;j<m;j++){
                if(s[i+j]!=t[j]){
                    
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
        int gcd=__gcd(str1.size(),str2.size());
        for(int i=0;i<=gcd;i++){
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