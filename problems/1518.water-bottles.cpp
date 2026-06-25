// @leetcode id=1518 questionId=1642 slug=water-bottles lang=cpp site=leetcode.com title="Water Bottles"
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drunk = 0;
        int empty = 0;

        while (numBottles > 0) {
            drunk += numBottles;
            empty += numBottles;
            numBottles = empty / numExchange;
            empty %= numExchange;
        }

        return drunk;
    }
};
