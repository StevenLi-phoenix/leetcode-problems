// @leetcode id=3502 questionId=3832 slug=minimum-cost-to-reach-every-position lang=cpp site=leetcode.com title="Minimum Cost to Reach Every Position"
class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> answer(cost.size());
        int best = INT_MAX;
        for (int i = 0; i < (int)cost.size(); i++) {
            best = min(best, cost[i]);
            answer[i] = best;
        }
        return answer;
    }
};
