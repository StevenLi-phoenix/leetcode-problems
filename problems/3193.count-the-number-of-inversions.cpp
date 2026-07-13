// @leetcode id=3193 questionId=3460 slug=count-the-number-of-inversions lang=cpp site=leetcode.com title="Count the Number of Inversions"
class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        // Build the permutation by inserting values 1..n-1 one at a time
        // among the i+1 available slots; inserting the i-th value creates
        // 0..i new inversions depending on the slot chosen. dp[i][j] =
        // number of ways to place the first i+1 values with exactly j
        // inversions; a requirement at index i forces dp[i][*] down to a
        // single count.
        const long long MOD = 1e9 + 7;
        int maxInv = n * (n - 1) / 2;

        vector<int> req(n, -1);
        for (auto& r : requirements) req[r[0]] = r[1];

        vector<long long> dp(maxInv + 1, 0);
        dp[0] = 1;
        if (req[0] != -1 && req[0] != 0) return 0;

        for (int i = 1; i < n; i++) {
            vector<long long> prefix(maxInv + 1);
            prefix[0] = dp[0];
            for (int t = 1; t <= maxInv; t++) prefix[t] = (prefix[t - 1] + dp[t]) % MOD;

            vector<long long> newDp(maxInv + 1, 0);
            for (int j = 0; j <= maxInv; j++) {
                long long hi = prefix[j];
                long long lo = (j - i - 1 >= 0) ? prefix[j - i - 1] : 0;
                newDp[j] = ((hi - lo) % MOD + MOD) % MOD;
            }

            if (req[i] != -1) {
                long long keep = (req[i] <= maxInv) ? newDp[req[i]] : 0;
                fill(newDp.begin(), newDp.end(), 0);
                if (req[i] <= maxInv) newDp[req[i]] = keep;
            }

            dp = move(newDp);
        }

        long long ans = 0;
        for (long long v : dp) ans = (ans + v) % MOD;
        return (int)ans;
    }
};
