// @leetcode id=1388 questionId=1489 slug=pizza-with-3n-slices lang=cpp site=leetcode.com title="Pizza With 3n Slices"
class Solution {
public:
    int solve(vector<int>& arr, int n) {
        int len = arr.size();
        vector<vector<int>> dp(len + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= n; j++) {
                int skip = dp[i - 1][j];
                int take = (i >= 2 ? dp[i - 2][j - 1] : (j == 1 ? 0 : INT_MIN)) + arr[i - 1];
                dp[i][j] = max(skip, take);
            }
        }

        return dp[len][n];
    }

    int maxSizeSlices(vector<int>& slices) {
        int total = slices.size();
        int n = total / 3;

        vector<int> withoutLast(slices.begin(), slices.end() - 1);
        vector<int> withoutFirst(slices.begin() + 1, slices.end());

        return max(solve(withoutLast, n), solve(withoutFirst, n));
    }
};
