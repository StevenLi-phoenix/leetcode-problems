// @leetcode id=2216 questionId=1355 slug=minimum-deletions-to-make-array-beautiful lang=cpp site=leetcode.com title="Minimum Deletions to Make Array Beautiful"
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        vector<int> stack;
        for (int x : nums) {
            if (stack.size() % 2 == 0) {
                stack.push_back(x);
            } else if (stack.back() != x) {
                stack.push_back(x);
            }
        }
        if (stack.size() % 2 != 0) stack.pop_back();
        return (int)nums.size() - (int)stack.size();
    }
};
