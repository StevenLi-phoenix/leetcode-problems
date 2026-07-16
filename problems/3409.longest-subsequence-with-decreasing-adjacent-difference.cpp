// @leetcode id=3409 questionId=3716 slug=longest-subsequence-with-decreasing-adjacent-difference lang=cpp site=leetcode.com title="Longest Subsequence With Decreasing Adjacent Difference"
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        const int MAXV = 300;
        vector<vector<int>> f(MAXV + 1, vector<int>(MAXV + 1, 0));
        vector<vector<int>> suffixMax(MAXV + 1, vector<int>(MAXV + 1, 0));
        vector<bool> seen(MAXV + 1, false);

        int globalBest = 1;

        for (int x : nums) {
            vector<int> newF(MAXV + 1, 0);
            int bestForX = 1;
            for (int v = 1; v <= MAXV; v++) {
                if (!seen[v]) continue;
                int diff = abs(x - v);
                int candidate = suffixMax[v][diff] + 1;
                newF[diff] = max(newF[diff], candidate);
                bestForX = max(bestForX, candidate);
            }

            for (int d = 0; d < MAXV; d++) f[x][d] = max(f[x][d], newF[d]);
            f[x][MAXV] = max(f[x][MAXV], 1);
            seen[x] = true;

            suffixMax[x][MAXV] = f[x][MAXV];
            for (int d = MAXV - 1; d >= 0; d--) {
                suffixMax[x][d] = max(f[x][d], suffixMax[x][d + 1]);
            }

            globalBest = max(globalBest, bestForX);
        }
        return globalBest;
    }
};
