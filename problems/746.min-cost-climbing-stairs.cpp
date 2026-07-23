// @leetcode id=746 questionId=747 slug=min-cost-climbing-stairs lang=cpp site=leetcode.com title="Min Cost Climbing Stairs"
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = 0, prev1 = 0;
        for (int i = 2; i <= n; i++) {
            int cur = min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
