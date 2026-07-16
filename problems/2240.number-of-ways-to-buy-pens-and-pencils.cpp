// @leetcode id=2240 questionId=2351 slug=number-of-ways-to-buy-pens-and-pencils lang=cpp site=leetcode.com title="Number of Ways to Buy Pens and Pencils"
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways = 0;
        for (long long pens = 0; pens * cost1 <= total; pens++) {
            long long remaining = total - pens * cost1;
            ways += remaining / cost2 + 1;
        }
        return ways;
    }
};
