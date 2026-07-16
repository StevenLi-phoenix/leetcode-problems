// @leetcode id=3795 questionId=4152 slug=minimum-subarray-length-with-distinct-sum-at-least-k lang=cpp site=leetcode.com title="Minimum Subarray Length With Distinct Sum At Least K"
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        long long distinctSum = 0;
        int l = 0;
        int best = INT_MAX;
        int n = nums.size();

        for (int r = 0; r < n; r++) {
            if (count[nums[r]]++ == 0) distinctSum += nums[r];

            while (distinctSum >= k) {
                best = min(best, r - l + 1);
                if (--count[nums[l]] == 0) distinctSum -= nums[l];
                l++;
            }
        }
        return best == INT_MAX ? -1 : best;
    }
};
