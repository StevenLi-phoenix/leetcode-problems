// @leetcode id=2589 questionId=2657 slug=minimum-time-to-complete-all-tasks lang=cpp site=leetcode.com title="Minimum Time to Complete All Tasks"
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<bool> on(2001, false);

        for (auto& t : tasks) {
            int start = t[0], end = t[1], duration = t[2];
            for (int i = start; i <= end; i++) {
                if (on[i]) duration--;
            }
            for (int i = end; i >= start && duration > 0; i--) {
                if (!on[i]) {
                    on[i] = true;
                    duration--;
                }
            }
        }

        int total = 0;
        for (int i = 0; i <= 2000; i++) if (on[i]) total++;
        return total;
    }
};
