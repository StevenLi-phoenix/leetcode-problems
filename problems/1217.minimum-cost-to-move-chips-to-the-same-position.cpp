// @leetcode id=1217 questionId=1329 slug=minimum-cost-to-move-chips-to-the-same-position lang=cpp site=leetcode.com title="Minimum Cost to Move Chips to The Same Position"
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for (int p : position) {
            if (p % 2 == 0) even++;
            else odd++;
        }
        return min(odd, even);
    }
};
