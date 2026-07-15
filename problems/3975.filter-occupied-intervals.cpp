// @leetcode id=3975 questionId=3724 slug=filter-occupied-intervals lang=cpp site=leetcode.com title="Filter Occupied Intervals"
class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> merged;
        for (auto& interval : occupiedIntervals) {
            if (!merged.empty() && interval[0] <= merged.back()[1] + 1) {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            } else {
                merged.push_back(interval);
            }
        }

        vector<vector<int>> result;
        for (auto& interval : merged) {
            int s = interval[0], e = interval[1];
            if (e < freeStart || s > freeEnd) {
                result.push_back({s, e});
            } else {
                if (s < freeStart) result.push_back({s, freeStart - 1});
                if (e > freeEnd) result.push_back({freeEnd + 1, e});
            }
        }
        return result;
    }
};
