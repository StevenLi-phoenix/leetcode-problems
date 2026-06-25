// @leetcode id=435 questionId=435 slug=non-overlapping-intervals lang=cpp site=leetcode.com title="Non-overlapping Intervals"
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // Sort by end time (greedy: keep intervals with earliest end)
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int count = 0; // number of intervals to remove
        int prevEnd = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) {
                // Overlap - remove this interval
                count++;
            } else {
                // No overlap - keep this interval
                prevEnd = intervals[i][1];
            }
        }
        
        return count;
    }
};
