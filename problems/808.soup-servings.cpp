// @leetcode id=808 questionId=826 slug=soup-servings lang=cpp site=leetcode.com title="Soup Servings"
class Solution {
public:
    double soupServings(int n) {
        if (n >= 4800) return 1.0;
        int m = (n + 24) / 25;
        memo.assign(m + 1, vector<double>(m + 1, -1.0));
        return dp(m, m);
    }

private:
    vector<vector<double>> memo;

    double dp(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if (memo[a][b] >= 0) return memo[a][b];
        double res = 0.25 * (dp(a - 4, b) + dp(a - 3, b - 1) + dp(a - 2, b - 2) + dp(a - 1, b - 3));
        memo[a][b] = res;
        return res;
    }
};
