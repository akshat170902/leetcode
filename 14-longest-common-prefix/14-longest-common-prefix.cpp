class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string s="";
        char r;
        for(int i=0;i<strs[0].size();i++){
            r=strs[0][i];
            for(int j=1;j<n;j++){
                if(i>=strs[j].size()||strs[j][i]!=r){
                    return s;
                }
            }
            s+=r;
        }
        return s;
    }
};