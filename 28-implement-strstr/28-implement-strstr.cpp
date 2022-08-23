class Solution {
public:
    void PiFunction(vector<int>&arr,string&s){
        int n=s.size();
        for(int i=1;i<n;i++){
            int j=arr[i-1];
            while(j>0&&s[i]!=s[j]){
                j=arr[j-1];
                
            }
            if(s[i]==s[j]){
                j++;
            }
            arr[i]=j;
        }
    }
    int knuthMoris(string &t,string&s){
        int n=s.size(),m=t.size();
        vector<int>arr(n);
        PiFunction(arr,s);
        int j=-1;
        // for(int i=0;i<n;i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
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