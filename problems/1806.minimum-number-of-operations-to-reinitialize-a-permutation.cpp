// @leetcode id=1806 questionId=1935 slug=minimum-number-of-operations-to-reinitialize-a-permutation lang=cpp site=leetcode.com title="Minimum Number of Operations to Reinitialize a Permutation"
class Solution {
public:
    int reinitializePermutation(int n) {
        int pos = 1;
        int steps = 0;
        do {
            if (pos < n / 2) pos = 2 * pos;
            else pos = 2 * (pos - n / 2) + 1;
            ++steps;
        } while (pos != 1);
        return steps;
    }
};
