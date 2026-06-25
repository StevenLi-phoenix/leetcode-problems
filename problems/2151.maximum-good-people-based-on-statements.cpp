// @leetcode id=2151 questionId=2272 slug=maximum-good-people-based-on-statements lang=cpp site=leetcode.com title="Maximum Good People Based on Statements"
class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int ans = 0;
        // Try all 2^n assignments (bitmask = who is good)
        for (int mask = 0; mask < (1 << n); mask++) {
            bool valid = true;
            // Check: for each good person i, their statements must be consistent
            for (int i = 0; i < n && valid; i++) {
                if (!(mask >> i & 1)) continue; // i is bad, skip
                // i is good, all statements are true
                for (int j = 0; j < n && valid; j++) {
                    if (statements[i][j] == 2) continue; // no statement
                    bool jGood = (mask >> j & 1) == 1;
                    if (statements[i][j] == 1 && !jGood) valid = false;
                    if (statements[i][j] == 0 && jGood) valid = false;
                }
            }
            if (valid) ans = max(ans, __builtin_popcount(mask));
        }
        return ans;
    }
};
