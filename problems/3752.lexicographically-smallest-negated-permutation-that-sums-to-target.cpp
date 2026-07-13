// @leetcode id=3752 questionId=4077 slug=lexicographically-smallest-negated-permutation-that-sums-to-target lang=cpp site=leetcode.com title="Lexicographically Smallest Negated Permutation that Sums to Target"
class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        // Flipping value k to -k changes the base sum (1+...+n) by -2k, so
        // the flip set must sum to (maxSum - target) / 2. Greedily flip
        // the largest available values first (always feasible for a
        // consecutive-integer target range), then place flipped values
        // (most negative first) before unflipped values (ascending) to
        // get the lexicographically smallest arrangement.
        long long maxSum = (long long)n * (n + 1) / 2;
        long long diff = maxSum - target;
        if (diff < 0 || diff > 2 * maxSum || diff % 2 != 0) return {};

        long long needFlip = diff / 2;
        vector<char> flipped(n + 1, 0);
        for (int i = n; i >= 1; i--) {
            if (needFlip >= i) {
                flipped[i] = 1;
                needFlip -= i;
            }
        }

        vector<int> result;
        for (int i = n; i >= 1; i--) if (flipped[i]) result.push_back(-i);
        for (int i = 1; i <= n; i++) if (!flipped[i]) result.push_back(i);
        return result;
    }
};
