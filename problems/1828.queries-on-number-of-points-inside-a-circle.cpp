// @leetcode id=1828 questionId=1939 slug=queries-on-number-of-points-inside-a-circle lang=cpp site=leetcode.com title="Queries on Number of Points Inside a Circle"
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            int cx = q[0], cy = q[1], r = q[2];
            int count = 0;
            for (auto& p : points) {
                int dx = p[0] - cx, dy = p[1] - cy;
                if (dx * dx + dy * dy <= r * r) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
