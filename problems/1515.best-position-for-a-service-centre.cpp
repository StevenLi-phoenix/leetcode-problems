// @leetcode id=1515 questionId=1638 slug=best-position-for-a-service-centre lang=cpp site=leetcode.com title="Best Position for a Service Centre"
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        int n = positions.size();
        double x = 0, y = 0;
        for (auto& p : positions) { x += p[0]; y += p[1]; }
        x /= n; y /= n;

        auto totalDist = [&](double cx, double cy) {
            double s = 0;
            for (auto& p : positions) {
                s += sqrt((cx - p[0]) * (cx - p[0]) + (cy - p[1]) * (cy - p[1]));
            }
            return s;
        };

        for (int iter = 0; iter < 2000; iter++) {
            double sumX = 0, sumY = 0, sumW = 0;
            for (auto& p : positions) {
                double dx = x - p[0], dy = y - p[1];
                double d = sqrt(dx * dx + dy * dy);
                double w = (d < 1e-9) ? 1e9 : 1.0 / d;
                sumX += p[0] * w;
                sumY += p[1] * w;
                sumW += w;
            }
            x = sumX / sumW;
            y = sumY / sumW;
        }

        return totalDist(x, y);
    }
};
