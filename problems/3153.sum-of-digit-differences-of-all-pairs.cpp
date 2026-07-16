// @leetcode id=3153 questionId=3416 slug=sum-of-digit-differences-of-all-pairs lang=cpp site=leetcode.com title="Sum of Digit Differences of All Pairs"
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<string> s(n);
        for (int i = 0; i < n; i++) s[i] = to_string(nums[i]);
        int digits = s[0].size();

        long long total = 0;
        long long totalPairs = (long long)n * (n - 1) / 2;
        for (int pos = 0; pos < digits; pos++) {
            long long cnt[10] = {0};
            for (int i = 0; i < n; i++) cnt[s[i][pos] - '0']++;
            long long samePairs = 0;
            for (int d = 0; d < 10; d++) samePairs += cnt[d] * (cnt[d] - 1) / 2;
            total += totalPairs - samePairs;
        }
        return total;
    }
};
