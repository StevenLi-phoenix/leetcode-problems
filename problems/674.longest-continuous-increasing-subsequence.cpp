// @leetcode id=674 questionId=674 slug=longest-continuous-increasing-subsequence lang=cpp site=leetcode.com title="Longest Continuous Increasing Subsequence"
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int best = 1, current = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > nums[i - 1]) current++;
            else current = 1;
            best = max(best, current);
        }
        return best;
    }
};
