// @leetcode id=2256 questionId=2342 slug=minimum-average-difference lang=cpp site=leetcode.com title="Minimum Average Difference"
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int v : nums) total += v;

        long long prefix = 0;
        long long best = LLONG_MAX;
        int bestIdx = 0;
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            long long avgFront = prefix / (i + 1);
            long long avgBack = (i == n - 1) ? 0 : (total - prefix) / (n - i - 1);
            long long diff = abs(avgFront - avgBack);
            if (diff < best) { best = diff; bestIdx = i; }
        }
        return bestIdx;
    }
};
