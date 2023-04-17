class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int ec) {
        vector<bool>v;
        int mx=*max_element(candies.begin(),candies.end());
        for(auto&cn:candies){
            v.push_back(mx<=cn+ec);
        }
        return v;
    }
};