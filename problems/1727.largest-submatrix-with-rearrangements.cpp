// @leetcode id=1727 questionId=1845 slug=largest-submatrix-with-rearrangements lang=cpp site=leetcode.com title="Largest Submatrix With Rearrangements"
class Solution {
    public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 1; i < m; i++)
    for (int j = 0; j < n; j++)
    if (matrix[i][j]) matrix[i][j] += matrix[i-1][j];
    int ans = 0;
    for (int i = 0; i < m; i++) {
    vector<int> row = matrix[i];
    sort(row.rbegin(), row.rend());
    for (int j = 0; j < n; j++)
    ans = max(ans, row[j] * (j + 1));
    }
    return ans;
    }
    };
