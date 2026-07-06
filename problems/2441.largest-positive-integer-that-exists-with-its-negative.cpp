// @leetcode id=2441 questionId=2524 slug=largest-positive-integer-that-exists-with-its-negative lang=cpp site=leetcode.com title="Largest Positive Integer That Exists With Its Negative"
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int best = -1;
        for (int x : nums) {
            if (x > best && seen.count(-x)) best = x;
        }
        return best;
    }
};
