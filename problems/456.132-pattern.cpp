// @leetcode id=456 questionId=456 slug=132-pattern lang=cpp site=leetcode.com title="132 Pattern"
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> stack;
        long long third = LLONG_MIN;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < third) return true;
            while (!stack.empty() && stack.back() < nums[i]) {
                third = stack.back();
                stack.pop_back();
            }
            stack.push_back(nums[i]);
        }
        return false;
    }
};
