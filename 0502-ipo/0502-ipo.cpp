class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        int n=p.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            v[i]={c[i],p[i]};
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            p[i]=v[i].first;
            c[i]=v[i].second;
        }
        priority_queue<int>pq;
        int ans=w;
        int i=0;
        int prev=-1;
        while(k){
            int idx=upper_bound(p.begin(),p.end(),ans)-p.begin()-1;
            
            while(i<=idx){
                pq.push(c[i]);
                i++;
            }
            if(pq.size()){
                ans+=pq.top();
                pq.pop();
            }
            prev=idx;
            k--;
        }
        return ans;
    }
};