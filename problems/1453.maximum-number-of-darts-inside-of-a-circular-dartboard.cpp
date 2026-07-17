// @leetcode id=1453 questionId=1563 slug=maximum-number-of-darts-inside-of-a-circular-dartboard lang=cpp site=leetcode.com title="Maximum Number of Darts Inside of a Circular Dartboard"
class Solution {
public:
    int numPoints(vector<vector<int>>& darts, int r) {
        int n = darts.size();
        int best = 1;
        const double EPS = 1e-6;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double x1 = darts[i][0], y1 = darts[i][1];
                double x2 = darts[j][0], y2 = darts[j][1];
                double dx = x2 - x1, dy = y2 - y1;
                double d = sqrt(dx * dx + dy * dy);
                if (d > 2.0 * r) continue;

                double midX = (x1 + x2) / 2.0, midY = (y1 + y2) / 2.0;
                double h = sqrt(max(0.0, (double)r * r - (d / 2.0) * (d / 2.0)));

                double offX = -dy / d * h;
                double offY = dx / d * h;

                for (int sign = -1; sign <= 1; sign += 2) {
                    double cx = midX + sign * offX;
                    double cy = midY + sign * offY;

                    int count = 0;
                    for (int k = 0; k < n; k++) {
                        double ddx = darts[k][0] - cx;
                        double ddy = darts[k][1] - cy;
                        if (ddx * ddx + ddy * ddy <= (double)r * r + EPS) count++;
                    }
                    best = max(best, count);
                }
            }
        }

        return best;
    }
};
