// @leetcode id=3797 questionId=4153 slug=count-routes-to-climb-a-rectangular-grid lang=cpp site=leetcode.com title="Count Routes to Climb a Rectangular Grid"
class Solution {
public:
    static const long long MOD = 1000000007;

    vector<long long> windowSum(vector<long long>& a, int radius) {
        int m = a.size();
        vector<long long> prefix(m + 1, 0);
        for (int i = 0; i < m; i++) prefix[i + 1] = (prefix[i] + a[i]) % MOD;
        vector<long long> res(m, 0);
        for (int c = 0; c < m; c++) {
            int lo = max(0, c - radius);
            int hi = min(m, c + radius + 1);
            res[c] = (prefix[hi] - prefix[lo] + MOD) % MOD;
        }
        return res;
    }

    int numberOfRoutes(vector<string>& grid, int d) {
        int n = grid.size();
        int m = grid[0].size();

        long long r1sq = (long long)d * d - 1;
        int R1 = 0;
        while ((long long)(R1 + 1) * (R1 + 1) <= r1sq) R1++;

        vector<long long> A(m, 0);
        for (int c = 0; c < m; c++) {
            if (grid[n - 1][c] == '.') A[c] = 1;
        }

        for (int r = n - 1; r >= 1; r--) {
            vector<long long> horizSum = windowSum(A, d);
            vector<long long> B(m, 0);
            for (int c = 0; c < m; c++) {
                long long val = (horizSum[c] - A[c] + MOD) % MOD;
                B[c] = (grid[r][c] == '.') ? val : 0;
            }

            vector<long long> fromA = windowSum(A, R1);
            vector<long long> fromB = windowSum(B, R1);

            vector<long long> nextA(m, 0);
            for (int c = 0; c < m; c++) {
                long long val = (fromA[c] + fromB[c]) % MOD;
                nextA[c] = (grid[r - 1][c] == '.') ? val : 0;
            }

            A = nextA;
        }

        vector<long long> finalSum = windowSum(A, d);
        long long ans = 0;
        for (int c = 0; c < m; c++) {
            if (grid[0][c] == '.') ans = (ans + finalSum[c]) % MOD;
        }

        return (int)ans;
    }
};
