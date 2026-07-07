// @leetcode id=747 questionId=748 slug=largest-number-at-least-twice-of-others lang=cpp site=leetcode.com title="Largest Number At Least Twice of Others"
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIdx = 0, secondMax = -1;
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] > nums[maxIdx]) {
                secondMax = nums[maxIdx];
                maxIdx = i;
            } else if (nums[i] > secondMax) {
                secondMax = nums[i];
            }
        }
        return nums[maxIdx] >= 2 * secondMax ? maxIdx : -1;
    }
};
