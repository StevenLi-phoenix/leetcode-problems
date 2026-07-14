// @leetcode id=2817 questionId=3000 slug=minimum-absolute-difference-between-elements-with-constraint lang=cpp site=leetcode.com title="Minimum Absolute Difference Between Elements With Constraint"
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        set<int> seen;
        int ans = INT_MAX;
        for (int i = x; i < n; i++) {
            seen.insert(nums[i - x]);
            auto it = seen.lower_bound(nums[i]);
            if (it != seen.end()) ans = min(ans, *it - nums[i]);
            if (it != seen.begin()) {
                --it;
                ans = min(ans, nums[i] - *it);
            }
        }
        return ans;
    }
};
