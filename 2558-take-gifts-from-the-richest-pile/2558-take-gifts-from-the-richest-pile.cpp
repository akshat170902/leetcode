class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // Create a max-heap from the 'gifts' array (using a priority_queue)
        priority_queue<int> giftsHeap(gifts.begin(), gifts.end());

        // Perform the operation 'k' times
        for (int i = 0; i < k; i++) {
            // Get the maximum element from the heap (top element)
            int maxElement = giftsHeap.top();
            giftsHeap.pop();

            // Insert the floor of the square root of the maximum element back
            // into the heap
            giftsHeap.push(sqrt(maxElement));
        }

        // Accumulate the sum of the elements in the heap
        long long numberOfRemainingGifts = 0;
        while (!giftsHeap.empty()) {
            numberOfRemainingGifts += giftsHeap.top();
            giftsHeap.pop();
        }
        return numberOfRemainingGifts;
    }
};