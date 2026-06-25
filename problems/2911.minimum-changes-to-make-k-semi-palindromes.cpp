// @leetcode id=2911 questionId=2879 slug=minimum-changes-to-make-k-semi-palindromes lang=cpp site=leetcode.com title="Minimum Changes to Make K Semi-palindromes"
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        
        // Precompute cost[i][j] = min changes to make substring s[i..j] a palindrome
        // Using O(n^2) DP
        vector<vector<int>> palCost(n, vector<int>(n, 0));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) palCost[i][j] = (len > 2) ? palCost[i+1][j-1] : 0;
                else palCost[i][j] = (len > 2) ? palCost[i+1][j-1] + 1 : 1;
            }
        }
        
        // v[i][j] = min changes to make s[i..j] semi-palindrome (length >= 2)
        vector<vector<int>> v(n, vector<int>(n, INT_MAX / 2));
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                int best = INT_MAX / 2;
                // try all valid divisors d of len, 1 <= d < len
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;
                    // d groups, each of size m = len/d
                    int m = len / d;
                    int totalCost = 0;
                    for (int g = 0; g < d; g++) {
                        // group g: positions i+g, i+g+d, i+g+2d, ..., i+g+(m-1)*d
                        // This is a strided sequence - NOT directly in palCost
                        // We compute palindrome cost manually
                        int lo = 0, hi = m - 1;
                        int c = 0;
                        while (lo < hi) {
                            int posL = i + g + lo * d;
                            int posR = i + g + hi * d;
                            if (s[posL] != s[posR]) c++;
                            lo++; hi--;
                        }
                        totalCost += c;
                    }
                    best = min(best, totalCost);
                }
                v[i][j] = best;
            }
        }
        
        // dp[i][j] = min changes to partition s[0..i] into j valid parts (each length >= 2)
        const int INF = 1e9;
        vector<vector<int>> dp(n, vector<int>(k + 1, INF));
        
        for (int i = 1; i < n; i++) {
            dp[i][1] = v[0][i];
        }
        
        for (int j = 2; j <= k; j++) {
            for (int i = 2*j - 1; i < n; i++) {
                for (int x = 2*j - 3; x <= i - 2; x++) {
                    if (dp[x][j-1] >= INF) continue;
                    int cost = v[x+1][i];
                    if (cost >= INF / 2) continue;
                    dp[i][j] = min(dp[i][j], dp[x][j-1] + cost);
                }
            }
        }
        
        return dp[n-1][k];
    }
};
