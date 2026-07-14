// @leetcode id=963 questionId=1003 slug=minimum-area-rectangle-ii lang=cpp site=leetcode.com title="Minimum Area Rectangle II"
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        // Key: (2*centerX, 2*centerY, distSquared) -> list of pair indices (i, j)
        map<tuple<int, int, long long>, vector<pair<int, int>>> groups;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cx2 = points[i][0] + points[j][0];
                int cy2 = points[i][1] + points[j][1];
                long long dx = points[i][0] - points[j][0];
                long long dy = points[i][1] - points[j][1];
                long long distSq = dx * dx + dy * dy;
                groups[{cx2, cy2, distSq}].push_back({i, j});
            }
        }

        double best = 0;
        for (auto& [key, diagonals] : groups) {
            int m = diagonals.size();
            for (int a = 0; a < m; a++) {
                for (int b = a + 1; b < m; b++) {
                    auto [p1, p3] = diagonals[a];
                    auto [p2, p4] = diagonals[b];
                    double side1 = hypot(points[p1][0] - points[p2][0], points[p1][1] - points[p2][1]);
                    double side2 = hypot(points[p1][0] - points[p4][0], points[p1][1] - points[p4][1]);
                    double area = side1 * side2;
                    if (best == 0 || area < best) best = area;
                }
            }
        }
        return best;
    }
};
