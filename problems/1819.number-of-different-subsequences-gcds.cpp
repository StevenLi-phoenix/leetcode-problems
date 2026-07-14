// @leetcode id=1819 questionId=1947 slug=number-of-different-subsequences-gcds lang=cpp site=leetcode.com title="Number of Different Subsequences GCDs"
class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        // For each candidate g, take the GCD of every present value that
        // is a multiple of g; if that combined GCD equals g exactly, some
        // subsequence achieves it (namely, all multiples of g present).
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> present(maxVal + 1, false);
        for (int v : nums) present[v] = true;

        int count = 0;
        for (int g = 1; g <= maxVal; g++) {
            int cur = 0;
            for (int m = g; m <= maxVal; m += g) {
                if (present[m]) cur = gcd(cur, m);
            }
            if (cur == g) count++;
        }
        return count;
    }
};
