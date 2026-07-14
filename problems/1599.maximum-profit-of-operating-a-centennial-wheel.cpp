// @leetcode id=1599 questionId=1721 slug=maximum-profit-of-operating-a-centennial-wheel lang=cpp site=leetcode.com title="Maximum Profit of Operating a Centennial Wheel"
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        long long waiting = 0;
        long long boarded = 0;
        long long bestProfit = 0;
        int bestRotation = -1;
        int rotation = 0;

        int i = 0;
        int n = customers.size();
        while (i < n || waiting > 0) {
            if (i < n) waiting += customers[i];
            long long board = min(waiting, 4LL);
            waiting -= board;
            boarded += board;
            rotation++;
            long long profit = boarded * boardingCost - (long long)rotation * runningCost;
            if (profit > bestProfit) {
                bestProfit = profit;
                bestRotation = rotation;
            }
            i++;
        }
        return bestRotation;
    }
};
