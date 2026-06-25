// @leetcode id=1320 questionId=1443 slug=minimum-distance-to-type-a-word-using-two-fingers lang=cpp site=leetcode.com title="Minimum Distance to Type a Word Using Two Fingers"
class Solution {
    public:
    int dist(int a, int b) {
    if (a == 26) return 0;
    return abs(a/6 - b/6) + abs(a%6 - b%6);
    }
    int minimumDistance(string word) {
    int n = word.size();
    vector<vector<int>> dp(n+1, vector<int>(27, INT_MAX));
    dp[0][26] = 0;
    for (int i = 0; i < n; i++) {
    int c = word[i] - 'A';
    for (int j = 0; j <= 26; j++) {
    if (dp[i][j] == INT_MAX) continue;
    int prev = (i == 0) ? 26 : (word[i-1] - 'A');
    dp[i+1][j] = min(dp[i+1][j], dp[i][j] + dist(prev, c));
    dp[i+1][prev] = min(dp[i+1][prev], dp[i][j] + dist(j, c));
    }
    }
    int ans = INT_MAX;
    for (int j = 0; j <= 26; j++) {
    ans = min(ans, dp[n][j]);
    }
    return ans;
    }
    };
