// @leetcode id=973 questionId=1014 slug=k-closest-points-to-origin lang=cpp site=leetcode.com title="K Closest Points to Origin"
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin() + k, points.end(),
                    [](const vector<int>& a, const vector<int>& b) {
                        return (long long)a[0] * a[0] + (long long)a[1] * a[1] <
                               (long long)b[0] * b[0] + (long long)b[1] * b[1];
                    });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
