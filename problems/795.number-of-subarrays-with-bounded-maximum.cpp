// @leetcode id=795 questionId=811 slug=number-of-subarrays-with-bounded-maximum lang=cpp site=leetcode.com title="Number of Subarrays with Bounded Maximum"
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        auto countLE = [&](int bound) -> long long {
            long long total = 0;
            int cur = 0;
            for (int v : nums) {
                if (v <= bound) cur++;
                else cur = 0;
                total += cur;
            }
            return total;
        };
        return (int)(countLE(right) - countLE(left - 1));
    }
};
