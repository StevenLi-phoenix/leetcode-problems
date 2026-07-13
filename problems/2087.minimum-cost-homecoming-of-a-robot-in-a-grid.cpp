// @leetcode id=2087 questionId=2192 slug=minimum-cost-homecoming-of-a-robot-in-a-grid lang=cpp site=leetcode.com title="Minimum Cost Homecoming of a Robot in a Grid"
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        // Costs are non-negative, so moving monotonically toward the target
        // (never overshooting or backtracking) is always optimal.
        long long total = 0;
        int r1 = startPos[0], r2 = homePos[0];
        for (int r = min(r1, r2); r <= max(r1, r2); r++)
            if (r != r1) total += rowCosts[r];

        int c1 = startPos[1], c2 = homePos[1];
        for (int c = min(c1, c2); c <= max(c1, c2); c++)
            if (c != c1) total += colCosts[c];

        return (int)total;
    }
};
