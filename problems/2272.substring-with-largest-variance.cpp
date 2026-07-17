// @leetcode id=2272 questionId=2360 slug=substring-with-largest-variance lang=cpp site=leetcode.com title="Substring With Largest Variance"
class Solution {
public:
    int largestVariance(string s) {
        vector<int> present(26, 0);
        for (char c : s) present[c - 'a'] = 1;

        int best = 0;

        const int NEG_INF = INT_MIN / 2;

        for (int a = 0; a < 26; a++) {
            if (!present[a]) continue;
            for (int b = 0; b < 26; b++) {
                if (a == b || !present[b]) continue;

                int bestEndingHere = 0;   // best sum ending here, no requirement of containing b
                int validEndingHere = NEG_INF; // best sum ending here that contains >=1 b

                for (char ch : s) {
                    int val = (ch - 'a' == a) ? 1 : (ch - 'a' == b ? -1 : 0);

                    int newValid;
                    if (val == -1) {
                        newValid = max({validEndingHere + val, bestEndingHere + val, val});
                    } else {
                        newValid = validEndingHere + val;
                    }
                    int newBest = max(bestEndingHere + val, val);

                    best = max(best, newValid);
                    bestEndingHere = newBest;
                    validEndingHere = newValid;
                }
            }
        }

        return best;
    }
};
