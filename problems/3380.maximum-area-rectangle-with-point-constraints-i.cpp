// @leetcode id=3380 questionId=3681 slug=maximum-area-rectangle-with-point-constraints-i lang=cpp site=leetcode.com title="Maximum Area Rectangle With Point Constraints I"
class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int n = points.size();
        set<pair<int, int>> pointSet;
        for (auto& p : points) pointSet.insert({p[0], p[1]});

        long long best = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 >= x2 || y1 >= y2) continue;
                if (!pointSet.count({x1, y2}) || !pointSet.count({x2, y1})) continue;

                bool valid = true;
                for (int k = 0; k < n && valid; k++) {
                    int x = points[k][0], y = points[k][1];
                    if (x == x1 && y == y1) continue;
                    if (x == x2 && y == y2) continue;
                    if (x == x1 && y == y2) continue;
                    if (x == x2 && y == y1) continue;
                    if (x >= x1 && x <= x2 && y >= y1 && y <= y2) valid = false;
                }
                if (valid) {
                    long long area = (long long)(x2 - x1) * (y2 - y1);
                    best = max(best, area);
                }
            }
        }
        return (int)best;
    }
};
