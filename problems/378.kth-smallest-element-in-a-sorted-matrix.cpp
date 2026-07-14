// @leetcode id=378 questionId=378 slug=kth-smallest-element-in-a-sorted-matrix lang=cpp site=leetcode.com title="Kth Smallest Element in a Sorted Matrix"
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n - 1][n - 1];

        auto countLE = [&](int x) -> int {
            int count = 0, row = n - 1, col = 0;
            while (row >= 0 && col < n) {
                if (matrix[row][col] <= x) { count += row + 1; col++; }
                else row--;
            }
            return count;
        };

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (countLE(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
