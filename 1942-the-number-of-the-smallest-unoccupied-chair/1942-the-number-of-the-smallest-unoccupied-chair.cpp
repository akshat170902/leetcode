class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        vector<vector<int>>v(2*n,vector<int>(3,0));
        for(int i=0;i<2*n;i+=2){
            v[i][0]=times[i/2][0];
            v[i][1]=1;
            v[i][2]=i/2;
            v[i+1][0]=times[i/2][1];
            v[i+1][1]=-1;
            v[i+1][2]=i/2;
        }
        sort(v.begin(),v.end());
        
        int chair=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_map<int,int>m;
        pq.push(chair);
        for(int i=0;i<2*n;i++){
            cout<<v[i][0]<<' '<<v[i][1]<<" "<<v[i][2]<<endl;
            if(v[i][1]==1){
                int val=pq.top();
                if(v[i][2]==targetFriend){
                    return val;
                }
                m[v[i][2]]=val;
                pq.pop();
                if(pq.empty()){
                    
                    pq.push(++chair);
                }
                
            }
            else{
                pq.push(m[v[i][2]]);
                
            }
        }
        return -1;
    }
};