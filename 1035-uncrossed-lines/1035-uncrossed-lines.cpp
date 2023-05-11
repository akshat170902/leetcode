class Solution {
    unordered_map<int,unordered_map<int,int>>mp;
public:
    int rec(int idx,int prev,vector<int>&n1,vector<int>&n2,unordered_map<int,vector<int>>&m){
        
        if(idx==n1.size()){
            return 0;
        }
        if(mp.count(idx)&&mp[idx].count(prev)){
            return mp[idx][prev];
        }
        vector<int>temp=m[n1[idx]];
        int res=0;
        auto val=upper_bound(temp.begin(),temp.end(),prev);
        if(val!=temp.end()){
            res=rec(idx+1,*val,n1,n2,m)+1;
        }
        int ans=rec(idx+1,prev,n1,n2,m);
        return mp[idx][prev]=max(res,ans);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,vector<int>>m;
        
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]].push_back(i);
        }
        return rec(0,-1,nums1,nums2,m);
    }
};