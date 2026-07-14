// @leetcode id=3071 questionId=3335 slug=minimum-operations-to-write-the-letter-y-on-a-grid lang=cpp site=leetcode.com title="Minimum Operations to Write the Letter Y on a Grid"
class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        int mid = n / 2;
        int yCount[3] = {0, 0, 0};
        int otherCount[3] = {0, 0, 0};
        int yTotal = 0, otherTotal = 0;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                bool isY;
                if (r <= mid && (c == r || c == n - 1 - r)) isY = true;
                else if (r > mid && c == mid) isY = true;
                else isY = false;

                if (isY) { yCount[grid[r][c]]++; yTotal++; }
                else { otherCount[grid[r][c]]++; otherTotal++; }
            }
        }

        int best = INT_MAX;
        for (int yVal = 0; yVal < 3; yVal++) {
            for (int oVal = 0; oVal < 3; oVal++) {
                if (yVal == oVal) continue;
                int cost = (yTotal - yCount[yVal]) + (otherTotal - otherCount[oVal]);
                best = min(best, cost);
            }
        }
        return best;
    }
};
