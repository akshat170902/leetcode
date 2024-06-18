class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size();
        
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            v.push_back({difficulty[i],profit[i]});
            
        }
        sort(v.begin(),v.end());
        int cur=0;
        for(int i=0;i<n;i++){
            cur=max(cur,v[i][1]);
            v[i][1]=cur;
            cout<<v[i][0]<<" "<<v[i][1]<<endl;
        }
        sort(difficulty.begin(),difficulty.end());
        int ans=0;
        for(int i=0;i<worker.size();i++){
            int val=upper_bound(difficulty.begin(),difficulty.end(),worker[i])-difficulty.begin();
            cout<<val<<endl;
            if(val==0){
                continue;
            }
            cout<<v[val-1][1]<<endl;
            ans+=v[val-1][1];
        }
        return ans;
    }
};