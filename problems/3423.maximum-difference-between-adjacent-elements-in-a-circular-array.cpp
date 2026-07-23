// @leetcode id=3423 questionId=3747 slug=maximum-difference-between-adjacent-elements-in-a-circular-array lang=cpp site=leetcode.com title="Maximum Difference Between Adjacent Elements in a Circular Array"
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int best = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            best = max(best, abs(nums[i] - nums[j]));
        }
        return best;
    }
};
