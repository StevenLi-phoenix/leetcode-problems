// @leetcode id=3531 questionId=3819 slug=count-covered-buildings lang=cpp site=leetcode.com title="Count Covered Buildings"
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int, pair<int, int>> rows, cols;

        for (auto& b : buildings) {
            int x = b[0], y = b[1];

            if (rows.find(x) == rows.end()) {
                rows[x] = {y, y};
            } else {
                rows[x].first = min(rows[x].first, y);
                rows[x].second = max(rows[x].second, y);
            }

            if (cols.find(y) == cols.end()) {
                cols[y] = {x, x};
            } else {
                cols[y].first = min(cols[y].first, x);
                cols[y].second = max(cols[y].second, x);
            }
        }

        int count = 0;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];

            bool hasLeft = rows[x].first < y;
            bool hasRight = rows[x].second > y;
            bool hasUp = cols[y].first < x;
            bool hasDown = cols[y].second > x;

            if (hasLeft && hasRight && hasUp && hasDown) {
                count++;
            }
        }

        return count;
    }
};
