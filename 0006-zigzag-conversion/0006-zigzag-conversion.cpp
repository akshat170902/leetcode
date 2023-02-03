class Solution {
public:
    string convert(string s, int n) {
        if(n==1){
            return s;
        }
        string ans="";
        int val=0;
        for(int i=2*(n-1);i>=0;i=i-2){
            int j=val;
            int turn=true;
            while(j<s.size()){
                
                ans+=s[j];
                j+=(i!=0&&i!=2*n-2?turn?i:2*n-2-i:2*n-2);
                turn=!turn;
            }
            val++;
        }
        return ans;
    }
};