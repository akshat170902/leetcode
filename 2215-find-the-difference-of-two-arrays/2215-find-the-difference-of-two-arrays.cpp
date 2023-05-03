class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int>a1,a2;
        unordered_map<int,int>m1,m2;
        for(auto&num:nums1){
            m1[num]++;
        }
        for(auto&num:nums2){
            
            m2[num]++;
        }
        for(auto&num:m1){
            if(!m2.count(num.first)){
                a1.push_back(num.first);
            }
        }
        for(auto&num:m2){
            if(!m1.count(num.first)){
                a2.push_back(num.first);
            }
        }
        
        
        return {a1,a2};
    }
};