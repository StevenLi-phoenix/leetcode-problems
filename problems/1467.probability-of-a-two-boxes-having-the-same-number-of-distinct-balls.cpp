// @leetcode id=1467 questionId=1577 slug=probability-of-a-two-boxes-having-the-same-number-of-distinct-balls lang=cpp site=leetcode.com title="Probability of a Two Boxes Having The Same Number of Distinct Balls"
class Solution {
public:
    double binom[60][60];

    void buildBinom() {
        for (int i = 0; i < 60; i++) {
            binom[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                binom[i][j] = binom[i - 1][j - 1] + (j <= i - 1 ? binom[i - 1][j] : 0);
            }
        }
    }

    double getProbability(vector<int>& balls) {
        buildBinom();
        int k = balls.size();
        int n = 0;
        for (int b : balls) n += b;
        n /= 2;

        double totalWays = binom[2 * n][n];
        double matchWays = 0;

        function<void(int, int, int, double)> dfs = [&](int idx, int sumBox1, int diffDistinct, double ways) {
            if (idx == k) {
                if (sumBox1 == n && diffDistinct == 0) matchWays += ways;
                return;
            }
            int cnt = balls[idx];
            for (int x = 0; x <= cnt; x++) {
                int nd = diffDistinct + (x > 0 ? 1 : 0) - (x < cnt ? 1 : 0);
                dfs(idx + 1, sumBox1 + x, nd, ways * binom[cnt][x]);
            }
        };

        dfs(0, 0, 0, 1.0);

        return matchWays / totalWays;
    }
};
