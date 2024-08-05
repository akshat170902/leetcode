class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        vector<string> distinctStrings;

        // Iterate through each string in the array
        for (int i = 0; i < n; i++) {
            string currentString = arr[i];
            bool isDistinct = true;

            // Check if the current string is distinct
            for (int j = 0; j < n; j++) {
                if (j == i) continue;  // Skip comparing with itself
                if (arr[j] == currentString) {
                    isDistinct = false;
                    break;
                }
            }

            // If the string is distinct, add it to the vector
            if (isDistinct) {
                distinctStrings.push_back(currentString);
            }
        }

        // Check if there are enough distinct strings
        if (distinctStrings.size() < k) {
            return "";
        }

        return distinctStrings[k - 1];
    }
};