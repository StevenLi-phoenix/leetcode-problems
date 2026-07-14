// @leetcode id=2919 questionId=3178 slug=minimum-increment-operations-to-make-array-beautiful lang=cpp site=leetcode.com title="Minimum Increment Operations to Make Array Beautiful"
class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n, 0);
        auto at = [&](int i) -> long long { return i < 0 ? 0 : dp[i]; };

        for (int i = 0; i < n; i++) {
            long long cost = max(0, k - nums[i]);
            dp[i] = cost + min({at(i - 1), at(i - 2), at(i - 3)});
        }
        return min({at(n - 1), at(n - 2), at(n - 3)});
    }
};
