class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        set<int> prev;
        int res=0;
        int n = nums.size();
        int minV = INT_MAX;
        for (int i = 0; i < n; i++){
            set<int> next;
            for (int v : prev)
                next.insert(v | nums[i]);
            next.insert(nums[i]);

            for (int v : next)
                minV = min(minV, abs(k - v));
            
            res=max(res,(int)prev.size());
            prev = next;
        }
        cout<<res<<endl;
        
        return minV;
    }
};