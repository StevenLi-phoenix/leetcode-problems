// @leetcode id=485 questionId=485 slug=max-consecutive-ones lang=cpp site=leetcode.com title="Max Consecutive Ones"
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0, cur = 0;
        for (int n : nums) {
            if (n == 1) {
                cur++;
                maxOnes = max(maxOnes, cur);
            } else {
                cur = 0;
            }
        }
        return maxOnes;
    }
};
