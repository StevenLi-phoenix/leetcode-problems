// @leetcode id=3040 questionId=3318 slug=maximum-number-of-operations-with-the-same-score-ii lang=cpp site=leetcode.com title="Maximum Number of Operations With the Same Score II"
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int c1 = solve(nums, nums[0] + nums[1]);
        int c2 = solve(nums, nums[n - 2] + nums[n - 1]);
        int c3 = solve(nums, nums[0] + nums[n - 1]);
        return max({c1, c2, c3});
    }

private:
    int solve(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dfs(nums, 0, n - 1, target, memo);
    }

    int dfs(vector<int>& nums, int l, int r, int target, vector<vector<int>>& memo) {
        if (r - l + 1 < 2) return 0;
        if (memo[l][r] != -1) return memo[l][r];

        int best = 0;
        if (nums[l] + nums[l + 1] == target) {
            best = max(best, 1 + dfs(nums, l + 2, r, target, memo));
        }
        if (nums[r - 1] + nums[r] == target) {
            best = max(best, 1 + dfs(nums, l, r - 2, target, memo));
        }
        if (nums[l] + nums[r] == target) {
            best = max(best, 1 + dfs(nums, l + 1, r - 1, target, memo));
        }
        return memo[l][r] = best;
    }
};
