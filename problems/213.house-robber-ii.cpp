// @leetcode id=213 questionId=213 slug=house-robber-ii lang=cpp site=leetcode.com title="House Robber II"
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robLine(nums, 0, n - 2), robLine(nums, 1, n - 1));
    }

private:
    int robLine(vector<int>& nums, int lo, int hi) {
        int prev = 0, cur = 0;
        for (int i = lo; i <= hi; ++i) {
            int next = max(cur, prev + nums[i]);
            prev = cur;
            cur = next;
        }
        return cur;
    }
};
