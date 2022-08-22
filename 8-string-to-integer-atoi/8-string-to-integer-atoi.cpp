#include<bits/stdc++.h>
class Solution {
public:
    int myAtoi(string s){
        int n=s.size();
        long long int ans=0,neg=1;
        bool flag =true;
        for(int i=0;i<n;i++){
            if(s[i]==' '&&flag){
                continue;
            }
            else if(s[i]=='-'&&flag){
                neg=-1;
                flag=false;
            }
            else if(s[i]=='+'&&flag){
                flag=false;
                neg=1;
            }
            else if(s[i]>='0'&&s[i]<='9'){
                ans=ans*10+(s[i]-'0');
                flag=false;
            }
            else{
                break;
            }
            if(neg*ans>INT_MAX)return INT_MAX;
            else if(neg*ans<INT_MIN) return INT_MIN;
        }
        ans=neg*ans;
        
        return ans;
    }
};