// @leetcode id=1403 questionId=1519 slug=minimum-subsequence-in-non-increasing-order lang=cpp site=leetcode.com title="Minimum Subsequence in Non-Increasing Order"
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int total = 0;
        for (int x : nums) total += x;
        vector<int> res;
        int subSum = 0;
        for (int x : nums) {
            subSum += x;
            res.push_back(x);
            if (subSum > total - subSum) break;
        }
        return res;
    }
};
