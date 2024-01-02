class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto&v:nums){
            m[v]++;
        }
        vector<vector<int>>a;
        bool flag=true;
        while(flag){
            bool temp=false;
            vector<int>b;
            for(auto&it:m){
                if(it.second){
                    b.push_back(it.first);
                    it.second--;
                    temp=true;
                }
            }
            flag=temp;
            if(!flag){
                break;
            }
            a.push_back(b);
        }
        return a;
    }
};