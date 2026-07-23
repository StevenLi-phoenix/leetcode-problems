// @leetcode id=3683 questionId=4012 slug=earliest-time-to-finish-one-task lang=cpp site=leetcode.com title="Earliest Time to Finish One Task"
class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int best = INT_MAX;
        for (auto& t : tasks) {
            best = min(best, t[0] + t[1]);
        }
        return best;
    }
};
