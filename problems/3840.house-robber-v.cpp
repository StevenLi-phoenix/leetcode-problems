// @leetcode id=3840 questionId=4062 slug=house-robber-v lang=cpp site=leetcode.com title="House Robber V"
class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        long long notRob = 0, doRob = nums[0];
        for (int i = 1; i < n; ++i) {
            long long newNotRob = max(notRob, doRob);
            long long newDoRob = nums[i] + (colors[i] == colors[i - 1] ? notRob : max(notRob, doRob));
            notRob = newNotRob;
            doRob = newDoRob;
        }
        return max(notRob, doRob);
    }
};
