class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<long long,long long>>v;
        for(int i=0;i<n;i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.begin(),v.end());
        long long cur=0,ans=0;
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int i=n-1;i>=0;i--){
            cout<<v[i].first<<" "<<v[i].second<<endl;
            if(n-i<k){
                pq.push(v[i].second);
                cur+=v[i].second;
                continue;
            }
            else if(n-i==k){
                pq.push(v[i].second);
                cur+=v[i].second;
                ans=max(ans,(cur)*(v[i].first));
            }
            else{
                
                ans=max(ans,(cur+v[i].second-pq.top())*(v[i].first));
                if(pq.top()<v[i].second){
                    cur-=pq.top();
                    cur+=v[i].second;
                    pq.pop();
                    pq.push(v[i].second);
                }
            }
            cout<<cur<<endl;
        }
        return ans;
    }
};