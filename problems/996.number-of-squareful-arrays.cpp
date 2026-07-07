// @leetcode id=996 questionId=1038 slug=number-of-squareful-arrays lang=cpp site=leetcode.com title="Number of Squareful Arrays"
class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<bool> used(n, false);
        int count = 0;

        auto isSquare = [](long long x) {
            long long r = (long long)sqrtl((long double)x);
            while (r * r < x) ++r;
            while (r * r > x) --r;
            return r * r == x;
        };

        function<void(int, int)> dfs = [&](int depth, int lastVal) {
            if (depth == n) {
                ++count;
                return;
            }
            for (int i = 0; i < n; ++i) {
                if (used[i]) continue;
                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
                if (depth > 0 && !isSquare((long long)lastVal + nums[i])) continue;

                used[i] = true;
                dfs(depth + 1, nums[i]);
                used[i] = false;
            }
        };

        dfs(0, 0);
        return count;
    }
};
