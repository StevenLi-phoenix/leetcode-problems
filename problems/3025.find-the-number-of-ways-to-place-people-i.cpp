// @leetcode id=3025 questionId=3278 slug=find-the-number-of-ways-to-place-people-i lang=cpp site=leetcode.com title="Find the Number of Ways to Place People I"
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int ax = points[i][0], ay = points[i][1];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int bx = points[j][0], by = points[j][1];
                if (ax > bx || ay < by) continue; // A must be upper-left of B

                bool empty = true;
                for (int k = 0; k < n && empty; k++) {
                    if (k == i || k == j) continue;
                    int x = points[k][0], y = points[k][1];
                    if (x >= ax && x <= bx && y <= ay && y >= by) empty = false;
                }
                if (empty) count++;
            }
        }
        return count;
    }
};
