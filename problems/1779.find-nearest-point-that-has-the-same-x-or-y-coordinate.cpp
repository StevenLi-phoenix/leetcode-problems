// @leetcode id=1779 questionId=1888 slug=find-nearest-point-that-has-the-same-x-or-y-coordinate lang=cpp site=leetcode.com title="Find Nearest Point That Has the Same X or Y Coordinate"
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minDist = INT_MAX;
        int result = -1;

        for (int i = 0; i < points.size(); i++) {
            int px = points[i][0];
            int py = points[i][1];

            if (px == x || py == y) {
                int dist = abs(px - x) + abs(py - y);
                if (dist < minDist) {
                    minDist = dist;
                    result = i;
                }
            }
        }

        return result;
    }
};
