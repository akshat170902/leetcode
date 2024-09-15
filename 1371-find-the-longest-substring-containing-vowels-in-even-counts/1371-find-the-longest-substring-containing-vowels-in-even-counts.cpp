class Solution {
public:
    int findLargestXor(vector<int>&v,int n){
        unordered_map<int,int>m;
        m[0]=-1;
        int largestLen=0,curXor=0;
        for(int i=0;i<n;i++){
            curXor^=v[i];
            if(curXor!=0&&m.count(curXor)==0){
                m[curXor]=i;
            }
            largestLen=max(largestLen,i-m[curXor]);
        }
        return largestLen;
    }
    int findTheLongestSubstring(string s) {
        unordered_map<int,int>m;
        m['a'-'a']=1;
        m['e'-'a']=2;
        m['i'-'a']=4;
        m['o'-'a']=8;
        m['u'-'a']=16;
        int n=s.size();
        
        vector<int>v(n);
        
        for(int i=0;i<n;i++){
            v[i]=m[s[i]-'a'];
        }
        
        return findLargestXor(v,n);
    }
};