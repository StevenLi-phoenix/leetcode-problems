// @leetcode id=410 questionId=410 slug=split-array-largest-sum lang=cpp site=leetcode.com title="Split Array Largest Sum"
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long lo = 0, hi = 0;
        for (int x : nums) { lo = max(lo, (long long)x); hi += x; }

        auto countParts = [&](long long limit) {
            int parts = 1;
            long long cur = 0;
            for (int x : nums) {
                if (cur + x > limit) { parts++; cur = x; }
                else cur += x;
            }
            return parts;
        };

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countParts(mid) <= k) hi = mid;
            else lo = mid + 1;
        }

        return (int)lo;
    }
};
