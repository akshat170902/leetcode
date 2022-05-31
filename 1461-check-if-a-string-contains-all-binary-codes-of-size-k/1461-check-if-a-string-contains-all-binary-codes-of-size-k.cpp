class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        if(s.size()<k||s.size()-k+1<pow(2,k))return false;
        unordered_map<string,bool>m;
    for(int j=0;j<pow(2,k);j++){
        string st="";
        for (int i = k-1; i >= 0; i--) {
        int l = j >> i;
        if (l & 1)
            st+="1";
        else
            st+="0";
    }
       
    m[st]=false;
}
        
        for(int i=0;i+k-1<s.size();i++){
            string st="";
            for(int j=0;j<k;j++){
                st+=s[i+j];
        } 
            m[st]=true;
    }
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second==false)return false;
        }
        return true;
    }
};