// @leetcode id=2311 questionId=2395 slug=longest-binary-subsequence-less-than-or-equal-to-k lang=cpp site=leetcode.com title="Longest Binary Subsequence Less Than or Equal to K"
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        long long value = 0;
        int bitsUsed = 0;
        int length = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                ++length;
                ++bitsUsed;
            } else if (bitsUsed < 31) {
                // beyond 31 bits, 2^bitsUsed alone already exceeds any valid k
                long long candidate = value + (1LL << bitsUsed);
                if (candidate <= k) {
                    value = candidate;
                    ++bitsUsed;
                    ++length;
                }
            }
        }
        return length;
    }
};
