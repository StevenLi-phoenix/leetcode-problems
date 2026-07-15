// @leetcode id=3111 questionId=3390 slug=minimum-rectangles-to-cover-points lang=cpp site=leetcode.com title="Minimum Rectangles to Cover Points"
class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int count = 0;
        long long coverLimit = LLONG_MIN;
        for (auto& p : points) {
            if (p[0] > coverLimit) {
                count++;
                coverLimit = p[0] + w;
            }
        }
        return count;
    }
};
