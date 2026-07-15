// @leetcode id=2162 questionId=2266 slug=minimum-cost-to-set-cooking-time lang=cpp site=leetcode.com title="Minimum Cost to Set Cooking Time"
class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int best = INT_MAX;

        int m1 = targetSeconds / 60, s1 = targetSeconds % 60;
        if (m1 <= 99) best = min(best, cost(m1, s1, startAt, moveCost, pushCost));

        int m2 = m1 - 1, s2 = s1 + 60;
        if (m2 >= 0 && s2 <= 99) best = min(best, cost(m2, s2, startAt, moveCost, pushCost));

        return best;
    }

private:
    int cost(int m, int s, int startAt, int moveCost, int pushCost) {
        string digits = to_string(m * 100 + s);
        int total = 0;
        char cur = '0' + startAt;
        for (char d : digits) {
            if (d != cur) total += moveCost;
            total += pushCost;
            cur = d;
        }
        return total;
    }
};
