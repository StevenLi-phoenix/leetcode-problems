// @leetcode id=3987 questionId=4351 slug=minimum-total-cost-to-process-all-elements lang=cpp site=leetcode.com title="Minimum Total Cost to Process All Elements"
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        long long resources = k;
        long long opsCount = 0;
        long long totalCost = 0;

        for (int x : nums) {
            long long deficit = (long long)x - resources;
            long long t = 0;
            if (deficit > 0) {
                t = (deficit + k - 1) / k;
            }
            if (t > 0) {
                long long term1 = (t % MOD) * (opsCount % MOD) % MOD;
                long long sumT = t * (t + 1) / 2;
                long long term2 = sumT % MOD;
                totalCost = (totalCost + term1 + term2) % MOD;
                opsCount += t;
                resources += t * k;
            }
            resources -= x;
        }
        return (int)totalCost;
    }
};
