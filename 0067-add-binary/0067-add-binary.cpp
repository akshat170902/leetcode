class Solution {
public:
    string addBinary(string a, string b) {
        
        if(a.size()<b.size()){
            swap(a,b);
        }
        int n=a.size(),m=b.size();
        string ans="";
        int carry=0;
        for(int i=0;i<a.size();i++){
            if(i>=b.size()){
                int val=(a[n-1-i]-'0'+carry);
                ans+=val%2+'0';
                carry=val/2;
            }
            else{
                int val=(a[n-1-i]-'0'+b[m-1-i]-'0'+carry);
                // cout<<val<<endl;
                ans+=val%2+'0';
                carry=val/2;
            }
        }
        while(carry){
            int val=(carry);
            ans+=val%2+'0';
            carry=val/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};