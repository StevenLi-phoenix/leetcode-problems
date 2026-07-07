// @leetcode id=45 questionId=45 slug=jump-game-ii lang=cpp site=leetcode.com title="Jump Game II"
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, curEnd = 0, farthest = 0;

        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            if (i == curEnd) {
                ++jumps;
                curEnd = farthest;
            }
        }
        return jumps;
    }
};
