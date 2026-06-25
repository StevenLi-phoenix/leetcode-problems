// @leetcode id=3225 questionId=3470 slug=maximum-score-from-grid-operations lang=cpp site=leetcode.com title="Maximum Score From Grid Operations"
class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // pre[j][i] = sum of grid[0..i-1][j] (column j prefix sums)
        vector<vector<long long>> pre(n, vector<long long>(n + 1, 0));
        for (int j = 0; j < n; j++)
            for (int i = 0; i < n; i++)
                pre[j][i + 1] = pre[j][i] + grid[i][j];
        
        // dp[a][b] = max total score for columns 0..j
        //   a = height of column j-1 (or 0 if j=0)
        //   b = height of column j
        // Contribution of col j added when we transition to col j+1
        //   = max(0, pre[j][max(a, c)] - pre[j][b])  where c = height of col j+1
        
        const long long NEG_INF = LLONG_MIN / 2;
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, NEG_INF));
        // Initialize for column 0: a=0 (virtual prev), b=any height
        for (int b = 0; b <= n; b++) dp[0][b] = 0;
        
        for (int j = 0; j < n - 1; j++) {
            vector<vector<long long>> ndp(n + 1, vector<long long>(n + 1, NEG_INF));
            
            for (int b = 0; b <= n; b++) {
                // We want, for each new height c:
                // ndp[b][c] = max over a of: dp[a][b] + max(0, pre[j][max(a,c)] - pre[j][b])
                //           = max over a of: dp[a][b] + (pre[j][max(a,c)] - pre[j][b] if max(a,c)>b else 0)
                
                // Case 1: max(a,c) = a (when a >= c)
                //   contribution = pre[j][a] - pre[j][b]  if a > b, else 0
                //   total = dp[a][b] + max(0, pre[j][a] - pre[j][b])
                //         = dp[a][b] + pre[j][a] - pre[j][b]  if a > b
                //         = dp[a][b]                           if a <= b
                //   Want max over a >= c of this
                
                // Case 2: max(a,c) = c (when c > a)
                //   contribution = pre[j][c] - pre[j][b]  if c > b, else 0
                //   total = dp[a][b] + max(0, pre[j][c] - pre[j][b])
                //   Want max over a < c of dp[a][b], then add max(0, pre[j][c]-pre[j][b])
                
                // For case 1, precompute sfx_geq_b[x] = max over a >= x, a > b of dp[a][b]+pre[j][a]
                //                                      AND sfx_leq_b[x] = max over a >= x, a <= b of dp[a][b]
                // Then sfx[x] = max(sfx_geq_b[x] - pre[j][b], sfx_leq_b[x]) 
                // But let's simplify: 
                //   sfx[x] = max over a >= x of (dp[a][b] + max(0, pre[j][a] - pre[j][b]))
                
                vector<long long> sfx(n + 2, NEG_INF);
                for (int a = n; a >= 0; a--) {
                    sfx[a] = sfx[a + 1];
                    if (dp[a][b] != NEG_INF) {
                        long long contrib = max(0LL, pre[j][a] - pre[j][b]);
                        sfx[a] = max(sfx[a], dp[a][b] + contrib);
                    }
                }
                
                // pfx[x] = max over a < x of dp[a][b]
                vector<long long> pfx(n + 2, NEG_INF);
                for (int a = 0; a <= n; a++) {
                    pfx[a + 1] = pfx[a];
                    if (dp[a][b] != NEG_INF)
                        pfx[a + 1] = max(pfx[a + 1], dp[a][b]);
                }
                
                for (int c = 0; c <= n; c++) {
                    long long best = NEG_INF;
                    // Case 1: a >= c, contribution uses a
                    if (sfx[c] != NEG_INF)
                        best = max(best, sfx[c]);
                    // Case 2: a < c, contribution uses c
                    if (pfx[c] != NEG_INF) {
                        long long contrib = max(0LL, pre[j][c] - pre[j][b]);
                        best = max(best, pfx[c] + contrib);
                    }
                    ndp[b][c] = best;
                }
            }
            dp = ndp;
        }
        
        // Add contribution of last column (n-1): only left neighbor (a), no right neighbor
        long long ans = 0;
        for (int a = 0; a <= n; a++)
            for (int b = 0; b <= n; b++)
                if (dp[a][b] != NEG_INF) {
                    long long contrib = max(0LL, pre[n-1][a] - pre[n-1][b]);
                    ans = max(ans, dp[a][b] + contrib);
                }
        
        return ans;
    }
};
