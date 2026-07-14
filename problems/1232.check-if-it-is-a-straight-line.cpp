// @leetcode id=1232 questionId=1349 slug=check-if-it-is-a-straight-line lang=cpp site=leetcode.com title="Check If It Is a Straight Line"
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int dx = coordinates[1][0] - x0, dy = coordinates[1][1] - y0;
        for (int i = 2; i < (int)coordinates.size(); i++) {
            int cx = coordinates[i][0] - x0, cy = coordinates[i][1] - y0;
            if ((long long)dx * cy - (long long)dy * cx != 0) return false;
        }
        return true;
    }
};
