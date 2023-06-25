class Solution {
    int mod=1e9+7;
    unordered_map<int,unordered_map<int,int>>m;
public:
    int rec(vector<int>&locations,int idx,int finish,int fuel){
        // cout<<idx<<" "<<fuel<<endl;
        int n=locations.size();
        if(fuel<0){
            return 0;
        }
        int ans=0;
        if(idx==finish){
            ans++;
        }
        
        if(m.count(idx)&&m[idx].count(fuel)){
            return m[idx][fuel];
        }
        
        for(int i=0;i<n;i++){
            if(idx!=i){
                
                ans=(ans+rec(locations,i,finish,fuel-abs(locations[idx]-locations[i])))%mod;
            }
        }
        return m[idx][fuel]=ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        start=locations[start];
        finish=locations[finish];
        sort(locations.begin(),locations.end());
        start=lower_bound(locations.begin(),locations.end(),start)-locations.begin();
        finish=lower_bound(locations.begin(),locations.end(),finish)-locations.begin();
        return rec(locations,start,finish,fuel);
    }
};