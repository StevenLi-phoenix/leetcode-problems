// @leetcode id=3523 questionId=3738 slug=make-array-non-decreasing lang=cpp site=leetcode.com title="Make Array Non-decreasing"
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        vector<int> stack;
        for (int x : nums) {
            if (stack.empty() || x >= stack.back()) {
                stack.push_back(x);
            }
        }
        return (int)stack.size();
    }
};
