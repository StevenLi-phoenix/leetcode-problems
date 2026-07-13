// @leetcode id=1987 questionId=2115 slug=number-of-unique-good-subsequences lang=cpp site=leetcode.com title="Number of Unique Good Subsequences"
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        // end0/end1 = count of distinct good subsequences ending in that
        // digit; appending a digit to every existing subsequence never
        // creates a duplicate (different endings differ by this last
        // digit's position class), and a leading digit only starts a new
        // one when it's '1' (a leading '0' subsequence is only ever "0").
        const long long MOD = 1e9 + 7;
        long long end0 = 0, end1 = 0;
        bool hasZero = false;

        for (char c : binary) {
            if (c == '1') {
                end1 = (end0 + end1 + 1) % MOD;
            } else {
                end0 = (end0 + end1) % MOD;
                hasZero = true;
            }
        }

        long long ans = (end0 + end1 + (hasZero ? 1 : 0)) % MOD;
        return (int)ans;
    }
};
