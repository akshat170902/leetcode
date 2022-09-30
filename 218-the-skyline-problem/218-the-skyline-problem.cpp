class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& a,vector<vector<int>> ans={}) {
        multiset<int> st = {0};
        multiset<vector<int>> walls;
        int curHeight = 0;
        for(auto ele:a){
            walls.insert({ele[0],-ele[2]});
            walls.insert({ele[1],ele[2]});
        };
        for(auto w:walls){
            if(w[1] < 0)st.insert(-w[1]);
            else st.erase(st.find(w[1]));
            
            if(*st.rbegin() != curHeight)
                ans.push_back({w[0],curHeight=*st.rbegin()});
        }
        
        return ans;
    }
};