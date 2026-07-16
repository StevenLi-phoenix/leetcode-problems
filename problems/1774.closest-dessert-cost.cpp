// @leetcode id=1774 questionId=1900 slug=closest-dessert-cost lang=cpp site=leetcode.com title="Closest Dessert Cost"
class Solution {
public:
    int best;

    void consider(int cost, int target) {
        int diff = abs(cost - target);
        int bestDiff = abs(best - target);
        if (diff < bestDiff || (diff == bestDiff && cost < best)) {
            best = cost;
        }
    }

    void backtrack(int idx, vector<int>& toppingCosts, int cost, int target) {
        if (idx == (int)toppingCosts.size()) {
            consider(cost, target);
            return;
        }
        for (int cnt = 0; cnt <= 2; cnt++) {
            backtrack(idx + 1, toppingCosts, cost + cnt * toppingCosts[idx], target);
        }
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        best = baseCosts[0];
        for (int b : baseCosts) {
            backtrack(0, toppingCosts, b, target);
        }
        return best;
    }
};
