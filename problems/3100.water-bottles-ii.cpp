// @leetcode id=3100 questionId=3336 slug=water-bottles-ii lang=cpp site=leetcode.com title="Water Bottles II"
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrunk = 0;
        int emptyBottles = 0;
        
        // Drink all initial bottles
        totalDrunk += numBottles;
        emptyBottles += numBottles;
        
        // Keep exchanging as long as we can
        while (emptyBottles >= numExchange) {
            emptyBottles -= numExchange;
            numExchange++;
            // Get 1 full bottle, drink it
            totalDrunk++;
            emptyBottles++;
        }
        
        return totalDrunk;
    }
};
