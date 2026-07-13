// @leetcode id=452 questionId=452 slug=minimum-number-of-arrows-to-burst-balloons lang=cpp site=leetcode.com title="Minimum Number of Arrows to Burst Balloons"
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        long long arrowPos = points[0][1];
        for (auto& p : points) {
            if (p[0] > arrowPos) {
                arrows++;
                arrowPos = p[1];
            }
        }
        return arrows;
    }
};
