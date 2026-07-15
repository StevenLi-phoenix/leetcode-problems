// @leetcode id=962 questionId=1002 slug=maximum-width-ramp lang=cpp site=leetcode.com title="Maximum Width Ramp"
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> stack;
        for (int i = 0; i < n; i++) {
            if (stack.empty() || nums[stack.back()] > nums[i]) stack.push_back(i);
        }

        int best = 0;
        for (int j = n - 1; j >= 0; j--) {
            while (!stack.empty() && nums[stack.back()] <= nums[j]) {
                best = max(best, j - stack.back());
                stack.pop_back();
            }
        }
        return best;
    }
};
