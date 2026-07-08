// @leetcode id=55 questionId=55 slug=jump-game lang=cpp site=leetcode.com title="Jump Game"
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (i > reach) return false;
            reach = max(reach, i + nums[i]);
        }
        return true;
    }
};
