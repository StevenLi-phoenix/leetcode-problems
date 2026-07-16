// @leetcode id=1901 questionId=2047 slug=find-a-peak-element-ii lang=cpp site=leetcode.com title="Find a Peak Element II"
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int lo = 0, hi = n - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int maxRow = 0;
            for (int i = 1; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) maxRow = i;
            }

            long long left = (mid > 0) ? mat[maxRow][mid - 1] : -1;
            long long right = (mid < n - 1) ? mat[maxRow][mid + 1] : -1;

            if (mat[maxRow][mid] > left && mat[maxRow][mid] > right) {
                return {maxRow, mid};
            } else if (right > mat[maxRow][mid]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return {-1, -1};
    }
};
