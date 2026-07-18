// @leetcode id=546 questionId=546 slug=remove-boxes lang=cpp site=leetcode.com title="Remove Boxes"
class Solution {
public:
    int dp[100][100][100];
    vector<int> b;

    int solve(int l, int r, int k) {
        if (l > r) return 0;
        if (dp[l][r][k] != -1) return dp[l][r][k];

        int l2 = l, k2 = k;
        while (l2 + 1 <= r && b[l2 + 1] == b[l]) {
            l2++;
            k2++;
        }

        int res = (k2 + 1) * (k2 + 1) + solve(l2 + 1, r, 0);

        for (int m = l2 + 1; m <= r; m++) {
            if (b[m] == b[l]) {
                res = max(res, solve(l2 + 1, m - 1, 0) + solve(m, r, k2 + 1));
            }
        }

        dp[l][r][k] = res;
        return res;
    }

    int removeBoxes(vector<int>& boxes) {
        b = boxes;
        memset(dp, -1, sizeof(dp));
        return solve(0, b.size() - 1, 0);
    }
};
