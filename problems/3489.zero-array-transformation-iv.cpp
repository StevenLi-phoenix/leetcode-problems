// @leetcode id=3489 questionId=3795 slug=zero-array-transformation-iv lang=cpp site=leetcode.com title="Zero Array Transformation IV"
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        auto feasible = [&](int k) {
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) continue;
                bitset<1001> dp;
                dp[0] = 1;
                for (int j = 0; j < k; j++) {
                    int l = queries[j][0], r = queries[j][1], val = queries[j][2];
                    if (l <= i && i <= r) {
                        dp |= dp << val;
                    }
                }
                if (!dp[nums[i]]) return false;
            }
            return true;
        };

        if (!feasible(m)) return -1;

        int lo = 0, hi = m;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
