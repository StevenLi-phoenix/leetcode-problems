// @leetcode id=2144 questionId=2248 slug=minimum-cost-of-buying-candies-with-discount lang=cpp site=leetcode.com title="Minimum Cost of Buying Candies With Discount"
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int total = 0;
        for (int i = 0; i < cost.size(); i++) {
            if ((i + 1) % 3 == 0) continue;
            total += cost[i];
        }
        return total;
    }
};
