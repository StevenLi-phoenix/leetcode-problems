// @leetcode id=198 questionId=198 slug=house-robber lang=cpp site=leetcode.com title="House Robber"
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, cur = 0;
        for (int v : nums) {
            int next = max(cur, prev + v);
            prev = cur;
            cur = next;
        }
        return cur;
    }
};
