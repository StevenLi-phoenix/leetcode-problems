// @leetcode id=2735 questionId=2810 slug=collecting-chocolates lang=cpp site=leetcode.com title="Collecting Chocolates"
class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> currentMin(nums.begin(), nums.end());
        long long sum = 0;
        for (long long v : currentMin) sum += v;

        long long best = sum;
        for (int k = 1; k < n; k++) {
            long long deltaSum = 0;
            for (int i = 0; i < n; i++) {
                long long val = nums[(i + k) % n];
                if (val < currentMin[i]) {
                    deltaSum += val - currentMin[i];
                    currentMin[i] = val;
                }
            }
            sum += deltaSum;
            long long total = (long long)k * x + sum;
            best = min(best, total);
        }
        return best;
    }
};
