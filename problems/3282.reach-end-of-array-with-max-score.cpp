// @leetcode id=3282 questionId=3528 slug=reach-end-of-array-with-max-score lang=cpp site=leetcode.com title="Reach End of Array With Max Score"
class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        // Jumping from i straight to the first j>i with nums[j] > nums[i] is
        // always at least as good as stopping earlier: the rate nums[i]
        // applies to every unit step in between regardless, and once a
        // larger value appears it should take over as the rate for anything
        // beyond it.
        int n = nums.size();
        long long score = 0;
        int i = 0;
        while (i < n - 1) {
            int j = i + 1;
            while (j < n - 1 && nums[j] <= nums[i]) j++;
            score += (long long)(j - i) * nums[i];
            i = j;
        }
        return score;
    }
};
