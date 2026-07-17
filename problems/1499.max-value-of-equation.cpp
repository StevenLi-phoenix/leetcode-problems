// @leetcode id=1499 questionId=1622 slug=max-value-of-equation lang=cpp site=leetcode.com title="Max Value of Equation"
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int,int>> dq; // (y - x, x)
        int best = INT_MIN;

        for (auto& p : points) {
            int x = p[0], y = p[1];
            while (!dq.empty() && x - dq.front().second > k) dq.pop_front();
            if (!dq.empty()) {
                best = max(best, dq.front().first + y + x);
            }
            while (!dq.empty() && dq.back().first <= y - x) dq.pop_back();
            dq.push_back({y - x, x});
        }
        return best;
    }
};
