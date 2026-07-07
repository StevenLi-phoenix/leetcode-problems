// @leetcode id=2654 questionId=2753 slug=minimum-number-of-operations-to-make-all-array-elements-equal-to-1 lang=cpp site=leetcode.com title="Minimum Number of Operations to Make All Array Elements Equal to 1"
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones > 0) return n - ones;

        int bestLen = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    bestLen = min(bestLen, j - i + 1);
                    break;
                }
            }
        }

        if (bestLen == INT_MAX) return -1;
        return (bestLen - 1) + (n - 1);
    }
};
