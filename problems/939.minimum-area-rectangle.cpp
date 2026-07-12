// @leetcode id=939 questionId=976 slug=minimum-area-rectangle lang=cpp site=leetcode.com title="Minimum Area Rectangle"
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int,int>> pts;
        for (auto& p : points) pts.insert({p[0], p[1]});

        int n = points.size();
        long long best = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 || y1 == y2) continue; // not a diagonal
                if (pts.count({x1, y2}) && pts.count({x2, y1})) {
                    long long area = (long long)abs(x1 - x2) * abs(y1 - y2);
                    best = min(best, area);
                }
            }
        }
        return best == LLONG_MAX ? 0 : (int)best;
    }
};
