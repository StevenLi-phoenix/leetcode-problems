// @leetcode id=3068 questionId=3307 slug=find-the-maximum-sum-of-node-values lang=cpp site=leetcode.com title="Find the Maximum Sum of Node Values"
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long baseSum = 0;
        int n = nums.size();
        vector<long long> diffs;
        diffs.reserve(n);

        for (int x : nums) {
            baseSum += x;
            diffs.push_back((long long)(x ^ k) - x);
        }

        long long total = baseSum;
        int flipCount = 0;
        long long smallestPositive = LLONG_MAX;
        long long largestNegative = LLONG_MIN;

        for (long long d : diffs) {
            if (d > 0) {
                total += d;
                flipCount++;
                smallestPositive = min(smallestPositive, d);
            } else {
                largestNegative = max(largestNegative, d);
            }
        }

        if (flipCount % 2 != 0) {
            long long revertLoss = (smallestPositive == LLONG_MAX) ? LLONG_MIN : -smallestPositive;
            long long addGain = (largestNegative == LLONG_MIN) ? LLONG_MIN : largestNegative;
            total += max(revertLoss, addGain);
        }

        return total;
    }
};
