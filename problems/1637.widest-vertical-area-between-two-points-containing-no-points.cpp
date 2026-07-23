// @leetcode id=1637 questionId=1742 slug=widest-vertical-area-between-two-points-containing-no-points lang=cpp site=leetcode.com title="Widest Vertical Area Between Two Points Containing No Points"
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xs;
        for (auto& p : points) xs.push_back(p[0]);
        sort(xs.begin(), xs.end());

        int best = 0;
        for (int i = 1; i < (int)xs.size(); i++) {
            best = max(best, xs[i] - xs[i - 1]);
        }
        return best;
    }
};
