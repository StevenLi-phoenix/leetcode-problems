// @leetcode id=812 questionId=830 slug=largest-triangle-area lang=cpp site=leetcode.com title="Largest Triangle Area"
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double best = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    long long x1 = points[j][0] - points[i][0], y1 = points[j][1] - points[i][1];
                    long long x2 = points[k][0] - points[i][0], y2 = points[k][1] - points[i][1];
                    double area = 0.5 * abs(x1 * y2 - x2 * y1);
                    best = max(best, area);
                }
            }
        }
        return best;
    }
};
