// @leetcode id=1072 questionId=1147 slug=flip-columns-for-maximum-number-of-equal-rows lang=cpp site=leetcode.com title="Flip Columns For Maximum Number of Equal Rows"
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> freq;
        for (auto& row : matrix) {
            string pattern;
            int first = row[0];
            for (int v : row) pattern += (v == first) ? '0' : '1';
            freq[pattern]++;
        }

        int best = 0;
        for (auto& [p, cnt] : freq) best = max(best, cnt);
        return best;
    }
};
