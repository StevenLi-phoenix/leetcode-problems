// @leetcode id=3834 questionId=4213 slug=merge-adjacent-equal-elements lang=cpp site=leetcode.com title="Merge Adjacent Equal Elements"
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> stack;
        for (int x : nums) {
            stack.push_back(x);
            while (stack.size() >= 2 && stack[stack.size() - 1] == stack[stack.size() - 2]) {
                long long sum = stack.back() + stack[stack.size() - 2];
                stack.pop_back();
                stack.pop_back();
                stack.push_back(sum);
            }
        }
        return stack;
    }
};
