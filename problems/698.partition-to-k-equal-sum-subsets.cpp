// @leetcode id=698 questionId=698 slug=partition-to-k-equal-sum-subsets lang=cpp site=leetcode.com title="Partition to K Equal Sum Subsets"
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;
        for (int x : nums) total += x;
        if (total % k != 0) return false;
        int target = total / k;

        sort(nums.begin(), nums.end());
        if (nums.back() > target) return false;

        vector<int> memo(1 << n, -1);
        vector<int> sumForMask(1 << n, 0);
        for (int mask = 1; mask < (1 << n); mask++) {
            int lsb = mask & (-mask);
            int idx = __builtin_ctz(lsb);
            sumForMask[mask] = sumForMask[mask ^ lsb] + nums[idx];
        }

        function<bool(int)> dfs = [&](int mask) -> bool {
            if (mask == (1 << n) - 1) return true;
            if (memo[mask] != -1) return memo[mask];

            int curSum = sumForMask[mask] % target;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) continue;
                if (curSum + nums[i] > target) continue;
                if (dfs(mask | (1 << i))) return memo[mask] = true;
            }
            return memo[mask] = false;
        };

        return dfs(0);
    }
};
