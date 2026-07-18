// @leetcode id=2835 questionId=3025 slug=minimum-operations-to-form-subsequence-with-target-sum lang=cpp site=leetcode.com title="Minimum Operations to Form Subsequence With Target Sum"
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long sum = 0;
        for (int x : nums) sum += x;
        if (sum < target) return -1;

        vector<long long> cnt(35, 0);
        for (int x : nums) {
            int b = 0;
            while ((1LL << b) != x) b++;
            cnt[b]++;
        }

        long long have = 0;
        long long ops = 0;

        for (int bit = 0; bit < 32; bit++) {
            have += cnt[bit];
            if ((target >> bit) & 1) {
                if (have == 0) {
                    int b2 = bit + 1;
                    while (cnt[b2] == 0) b2++;
                    cnt[b2]--;
                    ops += (b2 - bit);
                    have += (1LL << (b2 - bit)) - 1;
                } else {
                    have--;
                }
            }
            have /= 2;
        }

        return (int)ops;
    }
};
