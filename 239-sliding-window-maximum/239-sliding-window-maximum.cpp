class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        queue<int>q;
        multiset<int>st;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<k;i++){
            q.push(nums[i]);
            st.insert(nums[i]);
            
        }
        ans.push_back(*st.rbegin());
        for(int i=k;i<n;i++){
            q.push(nums[i]);
            int val=q.front();
            q.pop();
            auto it=st.find(val);
            st.erase(it);
            st.insert(nums[i]);
            ans.push_back(*st.rbegin());
        }
        return ans;
    }
};