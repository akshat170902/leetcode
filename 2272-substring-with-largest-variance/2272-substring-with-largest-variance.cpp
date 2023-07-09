class Solution {
public:
    int func(int i,int j,string&s){
        if(i==j){
            return 0;
        }
        char a='a'+i,b='a'+j;
        int n=s.size();
        int res=0,cura=0,curb=0,localm=0;
        for(int i=0;i<n;i++){
            s[i]==b?localm++:true;
        }
        for(int i=0;i<n;i++){
            if(s[i]==a){
                cura++;
                
            }
            if(s[i]==b){
                curb++;
                localm--;
                
            }
            if(cura&&curb){
                res=max(res,cura-curb);
            }
            if(cura-curb<0&&localm){
                cura=0,curb=0;
            }
        }
        // cout<<i<<" "<<j<<cur<<endl;
        return res;
    }
    int largestVariance(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                // cout<<i<<j<<endl;
                ans=max(func(i,j,s),ans);
            }
        }
        return ans;
    }
};