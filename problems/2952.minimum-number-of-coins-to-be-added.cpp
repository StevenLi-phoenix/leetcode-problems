// @leetcode id=2952 questionId=3231 slug=minimum-number-of-coins-to-be-added lang=cpp site=leetcode.com title="Minimum Number of Coins to be Added"
class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        long long reach = 0; // can make all values in [1, reach]
        int added = 0;
        int i = 0;
        while (reach < target) {
            // If current coin can extend our reach
            if (i < coins.size() && coins[i] <= reach + 1) {
                reach += coins[i];
                i++;
            } else {
                // Add coin with value reach + 1 to fill the gap
                reach += reach + 1;
                added++;
            }
        }
        return added;
    }
};
