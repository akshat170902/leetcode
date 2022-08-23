class Solution {
public:
    void PiFunction(vector<int>&lps,string&pat){
int M=pat.size();
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
    
    int knuthMoris(string &t,string&s){
        int n=s.size(),m=t.size();
        vector<int>arr(n);
        PiFunction(arr,s);
        int j=-1;
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<m;){
            // cout<<i<<" "<<j<<endl;
            while(j+1<n&&s[j+1]==t[i]){
                j++;
                i++;
            }
            if(j+1==n){
                return i-n;
            }
            else if(j!=-1){
                j=arr[j]-1;
            }
            else{
                i++;
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        
        return knuthMoris(haystack,needle);
    }
};