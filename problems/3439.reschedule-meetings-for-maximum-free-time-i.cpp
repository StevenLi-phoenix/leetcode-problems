// @leetcode id=3439 questionId=3743 slug=reschedule-meetings-for-maximum-free-time-i lang=cpp site=leetcode.com title="Reschedule Meetings for Maximum Free Time I"
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        // Moving k consecutive meetings to close up every gap between and
        // around them merges k+1 consecutive gaps into one free block;
        // sliding a window of size k+1 over the gap array finds the best.
        int n = startTime.size();
        vector<long long> gaps(n + 1);
        gaps[0] = startTime[0];
        for (int i = 1; i < n; i++) gaps[i] = startTime[i] - endTime[i - 1];
        gaps[n] = eventTime - endTime[n - 1];

        long long windowSum = 0;
        for (int i = 0; i <= k && i <= n; i++) windowSum += gaps[i];

        long long best = windowSum;
        for (int i = k + 1; i <= n; i++) {
            windowSum += gaps[i] - gaps[i - k - 1];
            best = max(best, windowSum);
        }
        return (int)best;
    }
};
