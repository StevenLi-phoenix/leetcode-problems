// @leetcode id=2335 questionId=2412 slug=minimum-amount-of-time-to-fill-cups lang=cpp site=leetcode.com title="Minimum Amount of Time to Fill Cups"
class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        int a = amount[0], b = amount[1], c = amount[2];
        if (a + b <= c) return c;
        return (a + b + c + 1) / 2;
    }
};
