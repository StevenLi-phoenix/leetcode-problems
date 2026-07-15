// @leetcode id=3394 questionId=3657 slug=check-if-grid-can-be-cut-into-sections lang=cpp site=leetcode.com title="Check if Grid can be Cut into Sections"
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return canCut(rectangles, 0, 2) || canCut(rectangles, 1, 3);
    }

private:
    bool canCut(vector<vector<int>>& rectangles, int startIdx, int endIdx) {
        vector<pair<int, int>> intervals;
        for (auto& r : rectangles) intervals.push_back({r[startIdx], r[endIdx]});
        sort(intervals.begin(), intervals.end());

        int groups = 1;
        int maxEnd = intervals[0].second;
        for (size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i].first >= maxEnd) {
                groups++;
                if (groups >= 3) return true;
                maxEnd = intervals[i].second;
            } else {
                maxEnd = max(maxEnd, intervals[i].second);
            }
        }
        return groups >= 3;
    }
};
