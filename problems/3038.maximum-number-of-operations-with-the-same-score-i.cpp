// @leetcode id=3038 questionId=3320 slug=maximum-number-of-operations-with-the-same-score-i lang=cpp site=leetcode.com title="Maximum Number of Operations With the Same Score I"
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int score = nums[0] + nums[1];
        int count = 0;

        for (int i = 0; i + 1 < nums.size(); i += 2) {
            if (nums[i] + nums[i+1] == score) {
                count++;
            } else {
                break;
            }
        }

        return count;
    }
};
