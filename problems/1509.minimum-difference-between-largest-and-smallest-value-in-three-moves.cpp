// @leetcode id=1509 questionId=1616 slug=minimum-difference-between-largest-and-smallest-value-in-three-moves lang=cpp site=leetcode.com title="Minimum Difference Between Largest and Smallest Value in Three Moves"
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        sort(nums.begin(), nums.end());

        int best = INT_MAX;
        for (int i = 0; i <= 3; i++) {
            int j = 3 - i;
            best = min(best, nums[n - 1 - j] - nums[i]);
        }
        return best;
    }
};
