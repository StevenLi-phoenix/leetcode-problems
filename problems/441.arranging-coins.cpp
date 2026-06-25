// @leetcode id=441 questionId=441 slug=arranging-coins lang=cpp site=leetcode.com title="Arranging Coins"
class Solution {
public:
    int arrangeCoins(int n) {
        return (int)((-1 + sqrt(1 + 8.0 * n)) / 2);
    }
};
