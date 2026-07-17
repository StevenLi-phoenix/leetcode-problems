// @leetcode id=2412 questionId=2499 slug=minimum-money-required-before-transactions lang=cpp site=leetcode.com title="Minimum Money Required Before Transactions"
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long totalLoss = 0;
        for (auto& t : transactions) {
            long long loss = max(0, t[0] - t[1]);
            totalLoss += loss;
        }

        long long best = 0;
        for (auto& t : transactions) {
            long long loss = max(0, t[0] - t[1]);
            long long candidate = totalLoss - loss + t[0];
            best = max(best, candidate);
        }

        return best;
    }
};
