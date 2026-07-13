// @leetcode id=3788 questionId=4173 slug=maximum-score-of-a-split lang=cpp site=leetcode.com title="Maximum Score of a Split"
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) suffixMin[i] = min(suffixMin[i + 1], nums[i]);

        long long best = LLONG_MIN, prefix = 0;
        for (int i = 0; i < n - 1; i++) {
            prefix += nums[i];
            best = max(best, prefix - suffixMin[i + 1]);
        }
        return best;
    }
};
