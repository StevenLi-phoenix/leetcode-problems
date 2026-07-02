// @leetcode id=2706 questionId=2756 slug=buy-two-chocolates lang=cpp site=leetcode.com title="Buy Two Chocolates"
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int first = INT_MAX, second = INT_MAX;
        for (int p : prices) {
            if (p < first) {
                second = first;
                first = p;
            } else if (p < second) {
                second = p;
            }
        }
        int cost = first + second;
        return cost <= money ? money - cost : money;
    }
};
