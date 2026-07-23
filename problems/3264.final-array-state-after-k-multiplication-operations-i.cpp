// @leetcode id=3264 questionId=3555 slug=final-array-state-after-k-multiplication-operations-i lang=cpp site=leetcode.com title="Final Array State After K Multiplication Operations I"
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int op = 0; op < k; op++) {
            int idx = 0;
            for (int i = 1; i < (int)nums.size(); i++) {
                if (nums[i] < nums[idx]) idx = i;
            }
            nums[idx] *= multiplier;
        }
        return nums;
    }
};
