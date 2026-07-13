// @leetcode id=3560 questionId=3879 slug=find-minimum-log-transportation-cost lang=cpp site=leetcode.com title="Find Minimum Log Transportation Cost"
class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        // At most one log can exceed k (guaranteed solvable with 3 trucks
        // for 2 logs). Cutting the oversized log as unevenly as possible
        // (one piece exactly k) minimizes the product cost.
        long long cost = 0;
        if (n > k) cost += (long long)(n - k) * k;
        if (m > k) cost += (long long)(m - k) * k;
        return cost;
    }
};
