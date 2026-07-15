// @leetcode id=2844 questionId=3046 slug=minimum-operations-to-make-a-special-number lang=cpp site=leetcode.com title="Minimum Operations to Make a Special Number"
class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int best = n; // delete everything -> "0"
        for (char c : num) {
            if (c == '0') { best = min(best, n - 1); break; }
        }

        vector<pair<char, char>> suffixes = {{'0', '0'}, {'2', '5'}, {'5', '0'}, {'7', '5'}};
        for (auto& [c1, c2] : suffixes) {
            for (int j = n - 1; j >= 1; j--) {
                if (num[j] != c2) continue;
                for (int i = j - 1; i >= 0; i--) {
                    if (num[i] == c1) {
                        int deletions = (n - 1 - j) + (j - 1 - i);
                        best = min(best, deletions);
                        break;
                    }
                }
            }
        }
        return best;
    }
};
