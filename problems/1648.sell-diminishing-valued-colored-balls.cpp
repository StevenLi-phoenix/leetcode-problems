// @leetcode id=1648 questionId=1771 slug=sell-diminishing-valued-colored-balls lang=cpp site=leetcode.com title="Sell Diminishing-Valued Colored Balls"
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const long long MOD = 1e9 + 7;
        sort(inventory.begin(), inventory.end(), greater<int>());
        int n = inventory.size();

        __int128 total = 0;
        long long remainingOrders = orders;
        long long width = 0;

        for (int i = 0; i < n && remainingOrders > 0; i++) {
            width++;
            long long nextVal = (i + 1 < n) ? inventory[i + 1] : 0;
            long long curVal = inventory[i];
            long long diff = curVal - nextVal;

            __int128 fullDrop = (__int128)width * diff;
            if (fullDrop <= remainingOrders) {
                __int128 sumSeries = (__int128)diff * (curVal + nextVal + 1) / 2;
                total += sumSeries * width;
                remainingOrders -= (long long)fullDrop;
            } else {
                long long k = remainingOrders / width;
                long long rem = remainingOrders % width;
                __int128 sumFullLevels = (__int128)k * curVal - (__int128)k * (k - 1) / 2;
                total += sumFullLevels * width;
                total += (__int128)rem * (curVal - k);
                remainingOrders = 0;
            }
        }

        return (int)(total % MOD);
    }
};
