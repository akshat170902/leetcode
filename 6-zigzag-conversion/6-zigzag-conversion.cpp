class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        vector<string>arr(numRows,"");
        int j=0;
        bool order=true;
        for(int i=0;i<s.size();i++){
            arr[j]+=s[i];
            if(j==0){
                order=true;
            }
            else if(j==numRows-1){
                order=false;
            }
            if(order){
                j++;
            }
            else{
                j--;
            }
        }
        string ans="";
        for(int i=0;i<numRows;i++){
            ans+=arr[i];
        }
        return ans;
    }
};