// @leetcode id=2616 questionId=2720 slug=minimize-the-maximum-difference-of-pairs lang=cpp site=leetcode.com title="Minimize the Maximum Difference of Pairs"
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        auto feasible = [&](int maxDiff) {
            int count = 0;
            int i = 0;
            while (i + 1 < n) {
                if (nums[i + 1] - nums[i] <= maxDiff) {
                    count++;
                    i += 2;
                } else {
                    i++;
                }
            }
            return count >= p;
        };

        int lo = 0, hi = nums[n - 1] - nums[0];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
