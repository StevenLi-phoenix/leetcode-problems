// @leetcode id=1760 questionId=1886 slug=minimum-limit-of-balls-in-a-bag lang=cpp site=leetcode.com title="Minimum Limit of Balls in a Bag"
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        auto opsNeeded = [&](int x) -> long long {
            long long ops = 0;
            for (int v : nums) {
                ops += (v - 1) / x;
            }
            return ops;
        };

        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (opsNeeded(mid) <= maxOperations) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
