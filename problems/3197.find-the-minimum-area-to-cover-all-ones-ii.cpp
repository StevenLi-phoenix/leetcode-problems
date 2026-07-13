// @leetcode id=3197 questionId=3459 slug=find-the-minimum-area-to-cover-all-ones-ii lang=cpp site=leetcode.com title="Find the Minimum Area to Cover All Ones II"
class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        // Enumerate every way to split the grid into 3 axis-aligned
        // regions via at most 2 cuts (2 horizontal, 2 vertical, or one of
        // each in 4 possible L-shaped arrangements), and for each region
        // take the tight bounding box area of its 1's (0 if empty).
        int rows = grid.size(), cols = grid[0].size();

        auto bboxArea = [&](int r1, int r2, int c1, int c2) -> int {
            if (r1 > r2 || c1 > c2) return 0;
            int minR = INT_MAX, maxR = INT_MIN, minC = INT_MAX, maxC = INT_MIN;
            for (int r = r1; r <= r2; r++) {
                for (int c = c1; c <= c2; c++) {
                    if (grid[r][c] == 1) {
                        minR = min(minR, r);
                        maxR = max(maxR, r);
                        minC = min(minC, c);
                        maxC = max(maxC, c);
                    }
                }
            }
            if (minR == INT_MAX) return 0;
            return (maxR - minR + 1) * (maxC - minC + 1);
        };

        int best = INT_MAX;

        // Two horizontal cuts: 3 row strips
        for (int i = 1; i < rows; i++) {
            for (int j = i + 1; j < rows; j++) {
                int area = bboxArea(0, i - 1, 0, cols - 1) +
                           bboxArea(i, j - 1, 0, cols - 1) +
                           bboxArea(j, rows - 1, 0, cols - 1);
                best = min(best, area);
            }
        }

        // Two vertical cuts: 3 column strips
        for (int i = 1; i < cols; i++) {
            for (int j = i + 1; j < cols; j++) {
                int area = bboxArea(0, rows - 1, 0, i - 1) +
                           bboxArea(0, rows - 1, i, j - 1) +
                           bboxArea(0, rows - 1, j, cols - 1);
                best = min(best, area);
            }
        }

        // One horizontal + one vertical cut: 4 L-shaped arrangements
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                // split top into left/right, bottom stays whole
                best = min(best, bboxArea(0, i - 1, 0, j - 1) + bboxArea(0, i - 1, j, cols - 1) +
                                      bboxArea(i, rows - 1, 0, cols - 1));
                // split bottom into left/right, top stays whole
                best = min(best, bboxArea(0, i - 1, 0, cols - 1) + bboxArea(i, rows - 1, 0, j - 1) +
                                      bboxArea(i, rows - 1, j, cols - 1));
                // split left into top/bottom, right stays whole
                best = min(best, bboxArea(0, i - 1, 0, j - 1) + bboxArea(i, rows - 1, 0, j - 1) +
                                      bboxArea(0, rows - 1, j, cols - 1));
                // split right into top/bottom, left stays whole
                best = min(best, bboxArea(0, rows - 1, 0, j - 1) + bboxArea(0, i - 1, j, cols - 1) +
                                      bboxArea(i, rows - 1, j, cols - 1));
            }
        }

        return best;
    }
};
