// @leetcode id=2871 questionId=3080 slug=split-array-into-maximum-number-of-subarrays lang=cpp site=leetcode.com title="Split Array Into Maximum Number of Subarrays"
class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int count = 0;
        int curAnd = -1;
        for (int x : nums) {
            curAnd &= x;
            if (curAnd == 0) {
                count++;
                curAnd = -1;
            }
        }
        return count == 0 ? 1 : count;
    }
};
