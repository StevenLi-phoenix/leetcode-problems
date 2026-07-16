// @leetcode id=2811 questionId=2916 slug=check-if-it-is-possible-to-split-array lang=cpp site=leetcode.com title="Check if it is Possible to Split Array"
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n <= 2) return true;
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] + nums[i + 1] >= m) return true;
        }
        return false;
    }
};
