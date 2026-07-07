// @leetcode id=1776 questionId=1902 slug=car-fleet-ii lang=cpp site=leetcode.com title="Car Fleet II"
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n, -1.0);
        vector<int> stk; // indices of cars ahead, still possibly relevant

        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty()) {
                int j = stk.back();
                if (cars[j][1] >= cars[i][1]) {
                    stk.pop_back();
                    continue;
                }
                double t = (double)(cars[j][0] - cars[i][0]) / (cars[i][1] - cars[j][1]);
                if (ans[j] < 0 || t <= ans[j]) break;
                stk.pop_back();
            }

            if (!stk.empty()) {
                int j = stk.back();
                ans[i] = (double)(cars[j][0] - cars[i][0]) / (cars[i][1] - cars[j][1]);
            }
            stk.push_back(i);
        }
        return ans;
    }
};
