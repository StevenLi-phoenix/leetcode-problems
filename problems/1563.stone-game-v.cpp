// @leetcode id=1563 questionId=1685 slug=stone-game-v lang=cpp site=leetcode.com title="Stone Game V"
class Solution {
public:
    vector<long long> prefix;
    vector<vector<int>> memo;

    long long sumRange(int i, int j) { // inclusive
        return prefix[j + 1] - prefix[i];
    }

    int solve(int i, int j) {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int best = 0;
        for (int k = i; k < j; k++) {
            long long leftSum = sumRange(i, k);
            long long rightSum = sumRange(k + 1, j);
            if (leftSum < rightSum) {
                best = max(best, (int)leftSum + solve(i, k));
            } else if (rightSum < leftSum) {
                best = max(best, (int)rightSum + solve(k + 1, j));
            } else {
                best = max(best, (int)leftSum + max(solve(i, k), solve(k + 1, j)));
            }
        }

        memo[i][j] = best;
        return best;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stoneValue[i];

        memo.assign(n, vector<int>(n, -1));
        return solve(0, n - 1);
    }
};
