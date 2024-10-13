class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Priority queue to store (value, list index, element index)
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;
        int maxVal = INT_MIN, rangeStart = 0, rangeEnd = INT_MAX;

        // Insert the first element from each list into the min-heap
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }

        // Continue until we can't proceed further
        while (pq.size() == nums.size()) {
            auto [minVal, indices] = pq.top();
            pq.pop();
            int row = indices.first, col = indices.second;

            // Update the smallest range
            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            // If possible, add the next element from the same row to the heap
            if (col + 1 < nums[row].size()) {
                int nextVal = nums[row][col + 1];
                pq.push({nextVal, {row, col + 1}});
                maxVal = max(maxVal, nextVal);
            }
        }

        return {rangeStart, rangeEnd};
    }
};