// @leetcode id=498 questionId=498 slug=diagonal-traverse lang=cpp site=leetcode.com title="Diagonal Traverse"
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        result.reserve(m * n);

        for (int d = 0; d <= m + n - 2; ++d) {
            int rStart = max(0, d - n + 1);
            int rEnd = min(d, m - 1);
            if (d % 2 == 0) {
                // upward: row decreasing
                for (int r = rEnd; r >= rStart; --r) result.push_back(mat[r][d - r]);
            } else {
                // downward: row increasing
                for (int r = rStart; r <= rEnd; ++r) result.push_back(mat[r][d - r]);
            }
        }
        return result;
    }
};
