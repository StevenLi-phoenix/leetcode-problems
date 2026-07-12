// @leetcode id=2250 questionId=2333 slug=count-number-of-rectangles-containing-each-point lang=cpp site=leetcode.com title="Count Number of Rectangles Containing Each Point"
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        // Heights are bounded by 100, so bucket lengths by height and binary
        // search within each bucket for a given point.
        vector<vector<int>> byHeight(101);
        for (auto& r : rectangles) byHeight[r[1]].push_back(r[0]);
        for (auto& v : byHeight) sort(v.begin(), v.end());

        vector<int> ans(points.size());
        for (int i = 0; i < (int)points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            int count = 0;
            for (int h = y; h <= 100; h++) {
                auto& v = byHeight[h];
                count += v.end() - lower_bound(v.begin(), v.end(), x);
            }
            ans[i] = count;
        }
        return ans;
    }
};
