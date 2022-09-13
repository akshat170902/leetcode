class Solution {
public:
    string binString(int val){
        string s="";
        for(int i=0;i<8;i++)
        {
            s+=('0'+val%2);
            val/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    bool validUtf8(vector<int>& data) {
        int n=data.size();
        for(int i=0;i<n;i++){
            
            string s=binString(data[i]);
            cout<<s<<endl;
            if(s[0]=='0'){
                continue;
            }
            else{
                if(s[1]=='1'&&s[2]=='0'){
                    i++;
                    if(i>=n){
                        return false;
                    }
                    string t=binString(data[i]);
                    if(t[0]!='1'&&t[1]!='0'){
                        return false;
                    }
                }
                else if(s[1]=='1'&&s[2]=='1'&&s[3]=='0'){
                    for(int j=0;j<2;j++){
                        i++;
                        if(i>=n){
                            return false;
                        }
                        string t=binString(data[i]);
                        cout<<s<<endl;
                        if(t[0]!='1'||t[1]!='0'){
                            return false;
                        }
                    }
                }
                else if(s[1]=='1'&&s[2]=='1'&&s[3]=='1'&&s[4]=='0'){
                    for(int j=0;j<3;j++){
                        i++;
                        if(i>=n){
                            return false;
                        }
                        string t=binString(data[i]);
                        if(t[0]!='1'||t[1]!='0'){
                            return false;
                        }
                    }
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};