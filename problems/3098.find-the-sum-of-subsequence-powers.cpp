// @leetcode id=3098 questionId=3316 slug=find-the-sum-of-subsequence-powers lang=cpp site=leetcode.com title="Find the Sum of Subsequence Powers"
class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        // For a threshold d, f(d) = number of length-k subsequences whose
        // every adjacent gap (in sorted order) is >= d. Summing d *
        // (f(d) - f(next larger candidate d')) over all candidate gap
        // values gives the sum of "min gap exactly d" * (that count),
        // i.e. exactly the sum of powers.
        const long long MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<long long> diffs;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                diffs.push_back((long long)nums[j] - nums[i]);
        sort(diffs.begin(), diffs.end());
        diffs.erase(unique(diffs.begin(), diffs.end()), diffs.end());

        auto f = [&](long long d) -> long long {
            vector<vector<long long>> dp(k + 1, vector<long long>(n, 0));
            for (int i = 0; i < n; i++) dp[1][i] = 1;
            for (int j = 2; j <= k; j++) {
                vector<long long> prefix(n);
                prefix[0] = dp[j - 1][0];
                for (int i = 1; i < n; i++) prefix[i] = (prefix[i - 1] + dp[j - 1][i]) % MOD;

                int p = -1; // largest index with nums[p] <= nums[i] - d
                for (int i = 0; i < n; i++) {
                    while (p + 1 < i && (long long)nums[i] - nums[p + 1] >= d) p++;
                    if (p >= 0) dp[j][i] = prefix[p];
                }
            }
            long long total = 0;
            for (int i = 0; i < n; i++) total = (total + dp[k][i]) % MOD;
            return total;
        };

        int m = diffs.size();
        vector<long long> fVals(m);
        for (int t = 0; t < m; t++) fVals[t] = f(diffs[t]);

        long long ans = 0;
        for (int t = 0; t < m; t++) {
            long long nextF = (t + 1 < m) ? fVals[t + 1] : 0;
            long long cnt = ((fVals[t] - nextF) % MOD + MOD) % MOD;
            ans = (ans + (diffs[t] % MOD) * cnt) % MOD;
        }
        return (int)ans;
    }
};
