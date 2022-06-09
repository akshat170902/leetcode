class Solution {
public:
    vector<int> twoSum(vector<int>& number, int target) {
        unordered_map<int,int>m;
        vector<int>sum;
        for(int i=0;i<number.size();i++){
             
            if(m.count(target-number[i])){
                sum.push_back(m[target-number[i]]+1);
                sum.push_back(i+1);
                break;
            }
            m[number[i]]=i;
        }
        
        return sum;
    }
};