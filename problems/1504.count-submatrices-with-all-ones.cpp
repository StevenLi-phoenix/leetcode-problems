// @leetcode id=1504 questionId=1628 slug=count-submatrices-with-all-ones lang=cpp site=leetcode.com title="Count Submatrices With All Ones"
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n, 0);
        int ans = 0;
        
        for (int i = 0; i < m; i++) {
            // Update heights
            for (int j = 0; j < n; j++) {
                height[j] = mat[i][j] == 0 ? 0 : height[j] + 1;
            }
            // For this row, count submatrices with bottom at row i
            // dp[j] = number of submatrices with bottom-right corner at (i, j)
            // Use stack to compute: for each j, how many consecutive heights >= height[k]
            // where k ranges from some previous index to j
            vector<int> dp(n, 0);
            stack<int> stk; // monotonic stack
            for (int j = 0; j < n; j++) {
                while (!stk.empty() && height[stk.top()] >= height[j]) {
                    stk.pop();
                }
                if (stk.empty()) {
                    // All columns 0..j have height >= height[j]
                    dp[j] = (j + 1) * height[j];
                } else {
                    // Columns stk.top()+1..j have height >= height[j]
                    dp[j] = dp[stk.top()] + (j - stk.top()) * height[j];
                }
                stk.push(j);
                ans += dp[j];
            }
        }
        return ans;
    }
};
