class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        vector<int>vis(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<candidates&&i<n;i++){
            if(!vis[i]){
                pq.push({costs[i],i});
                vis[i]=1;
            }
            if(!vis[n-i-1]){
                cout<<costs[n-i-1]<<endl;
                pq.push({costs[n-i-1],n-i-1});
                vis[n-1-i]=1;
            }
        }
        int low=candidates,high=n-candidates-1;
        long long ans=0;
        while(k--){
            auto [x,y]=pq.top();
            pq.pop();
            cout<<x<<' '<<y<<endl;
            ans+=x;
            if(y<low&&low<n){
                if(!vis[low]){
                    pq.push({costs[low],low});
                    vis[low]=1;
                    low++;
                    
                }
            }
            else if(y>high&&high>=0){
                if(!vis[high]){
                    pq.push({costs[high],high});
                    vis[high]=1;
                    high--;

                }
            }
            
        }
        return ans;
    }
};