// @leetcode id=3702 questionId=4033 slug=longest-subsequence-with-non-zero-bitwise-xor lang=cpp site=leetcode.com title="Longest Subsequence With Non-Zero Bitwise XOR"
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXor = 0;
        bool hasNonZero = false;
        for (int x : nums) {
            totalXor ^= x;
            if (x != 0) hasNonZero = true;
        }

        if (totalXor != 0) return n;
        if (hasNonZero) return n - 1;
        return 0;
    }
};
