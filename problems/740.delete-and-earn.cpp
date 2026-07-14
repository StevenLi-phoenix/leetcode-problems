// @leetcode id=740 questionId=740 slug=delete-and-earn lang=cpp site=leetcode.com title="Delete and Earn"
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<long long> sum(maxVal + 1, 0);
        for (int v : nums) sum[v] += v;

        long long prev2 = 0, prev1 = 0;
        for (int v = 1; v <= maxVal; v++) {
            long long cur = max(prev1, prev2 + sum[v]);
            prev2 = prev1;
            prev1 = cur;
        }
        return (int)prev1;
    }
};
