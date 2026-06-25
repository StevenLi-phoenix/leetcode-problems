// @leetcode id=3027 questionId=3277 slug=find-the-number-of-ways-to-place-people-ii lang=cpp site=leetcode.com title="Find the Number of Ways to Place People II"
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        // Sort by x ascending, then y descending
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int m = INT_MIN; // max y seen among intermediates with y <= points[i].y
            for (int j = i + 1; j < n; j++) {
                // points[j].x >= points[i].x (sorted)
                if (points[j][1] <= points[i][1]) {
                    // Bob (j) is at or below Alice (i)
                    // Valid if m < points[j][1] (no intermediate in rectangle)
                    if (m < points[j][1]) {
                        ans++;
                    }
                    // Update m with this j's y (for future js)
                    m = max(m, points[j][1]);
                }
            }
        }
        return ans;
    }
};
