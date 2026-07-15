// @leetcode id=1508 questionId=1615 slug=range-sum-of-sorted-subarray-sums lang=cpp site=leetcode.com title="Range Sum of Sorted Subarray Sums"
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const long long MOD = 1e9 + 7;
        vector<long long> sums;
        sums.reserve((size_t)n * (n + 1) / 2);
        for (int i = 0; i < n; i++) {
            long long s = 0;
            for (int j = i; j < n; j++) {
                s += nums[j];
                sums.push_back(s);
            }
        }
        sort(sums.begin(), sums.end());

        long long total = 0;
        for (int i = left - 1; i <= right - 1; i++) {
            total = (total + sums[i]) % MOD;
        }
        return (int)total;
    }
};
