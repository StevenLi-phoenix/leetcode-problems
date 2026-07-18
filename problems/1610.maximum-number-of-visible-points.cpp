// @leetcode id=1610 questionId=1733 slug=maximum-number-of-visible-points lang=cpp site=leetcode.com title="Maximum Number of Visible Points"
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int atLocation = 0;
        vector<double> angles;
        double PI = acos(-1.0);

        for (auto& p : points) {
            int dx = p[0] - location[0];
            int dy = p[1] - location[1];
            if (dx == 0 && dy == 0) {
                atLocation++;
                continue;
            }
            double ang = atan2((double)dy, (double)dx) * 180.0 / PI;
            angles.push_back(ang);
        }

        sort(angles.begin(), angles.end());
        int n = angles.size();
        for (int i = 0; i < n; i++) angles.push_back(angles[i] + 360.0);

        int best = 0;
        int left = 0;
        for (int right = 0; right < (int)angles.size(); right++) {
            while (angles[right] - angles[left] > (double)angle) left++;
            best = max(best, right - left + 1);
        }

        return best + atLocation;
    }
};
