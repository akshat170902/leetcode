class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        unordered_map<int,int>m;
    
        vector<vector<int>>graph(n+1);
        
        for(int i=0;i<trust.size();i++){
            m[trust[i][1]]++;
            graph[trust[i][0]].push_back(trust[i][1]);
        }
        
        for(int i=1;i<=n;i++){
            if(m[i]==n-1&&graph[i].size()==0){
                return i;
            }
        }
        return -1;
        
    }
};