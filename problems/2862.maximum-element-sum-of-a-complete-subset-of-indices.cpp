// @leetcode id=2862 questionId=3047 slug=maximum-element-sum-of-a-complete-subset-of-indices lang=cpp site=leetcode.com title="Maximum Element-Sum of a Complete Subset of Indices"
class Solution {
public:
    int squareFreePart(int x) {
        int result = 1;
        for (int p = 2; (long long)p * p <= x; p++) {
            int cnt = 0;
            while (x % p == 0) { x /= p; cnt++; }
            if (cnt % 2 == 1) result *= p;
        }
        if (x > 1) result *= x;
        return result;
    }

    long long maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, long long> groupSum;

        for (int i = 1; i <= n; i++) {
            int sf = squareFreePart(i);
            groupSum[sf] += nums[i - 1];
        }

        long long best = 0;
        for (auto& [k, v] : groupSum) best = max(best, v);

        return best;
    }
};
