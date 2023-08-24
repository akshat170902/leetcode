class Solution {
public:
    vector<string> ans;

    string space(int c) {
        return string(c, ' ');
    }

    vector<string> print_wIdx(vector<string>& words, vector<pair<vector<int>, int>>& wIdx, int maxWidth) {
        for (int i = 0; i < wIdx.size(); i++) {
            int numWords = wIdx[i].first.size();
            int totalLen = wIdx[i].second;
            int totalSpaces = maxWidth - totalLen;
            int numGaps = numWords - 1;
            int numSpaces = 1;
            int remainingSpaces = 0;

            if (numGaps > 0) {
                numSpaces = totalSpaces / numGaps;
                remainingSpaces = totalSpaces % numGaps;
            }

            string line = words[wIdx[i].first[0]]; // Start with the first word
            for (int j = 1; j < numWords; j++) {
                if (i == wIdx.size() - 1) {
                    // Last line, left justify
                    line += space(1);
                } else {
                    line += space(numSpaces + (remainingSpaces > 0 ? 1 : 0));
                    remainingSpaces--;
                }
                line += words[wIdx[i].first[j]];
            }

            if (line.size() < maxWidth)
                line += space(maxWidth - line.size());

            ans.push_back(line);
        }

        return ans;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<pair<vector<int>, int>> wIdx(1);
        int cur = 0;
        int len = 0;
        for (int i = 0; i < n; i++) {
            int wlen = words[i].size();
            len += wlen;
            if (len > maxWidth) {
                wIdx.push_back({{i}, wlen});
                cur++;
                len = wlen;
            } else {
                wIdx[cur].first.push_back(i);
                wIdx[cur].second += wlen;
            }
            len++; // Account for the space after each word
        }

        return print_wIdx(words, wIdx, maxWidth);
    }
};
