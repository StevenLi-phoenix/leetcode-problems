// @leetcode id=3776 questionId=4018 slug=minimum-moves-to-balance-circular-array lang=cpp site=leetcode.com title="Minimum Moves to Balance Circular Array"
class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        long long sum = 0;
        int k = -1;
        for (int i = 0; i < n; i++) {
            sum += balance[i];
            if (balance[i] < 0) k = i;
        }
        if (sum < 0) return -1;
        if (k == -1) return 0;

        long long remaining = -(long long)balance[k];
        long long totalCost = 0;

        for (int d = 1; d < n && remaining > 0; d++) {
            int idx1 = (k - d % n + n) % n;
            int idx2 = (k + d) % n;

            if (idx1 == idx2) {
                long long take = min((long long)balance[idx1], remaining);
                totalCost += take * d;
                remaining -= take;
            } else {
                long long take1 = min((long long)balance[idx1], remaining);
                totalCost += take1 * d;
                remaining -= take1;
                if (remaining > 0) {
                    long long take2 = min((long long)balance[idx2], remaining);
                    totalCost += take2 * d;
                    remaining -= take2;
                }
            }
        }
        return totalCost;
    }
};
