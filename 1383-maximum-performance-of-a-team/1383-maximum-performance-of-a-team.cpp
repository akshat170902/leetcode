class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mod=1e9+7;
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({efficiency[i],speed[i]});
        }
        sort(p.begin(),p.end(),greater<pair<int,int>>());
        long long  cur=0;
        long long  eff=0,sum=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            int e=p[i].first;
            int s=p[i].second;
            pq.push(s);
            sum+=s;
            while(pq.size()>k){
                sum-=pq.top();
                pq.pop();
                
            }
            cur=max(cur,sum*e);
        }
        return cur%mod;
    }
};