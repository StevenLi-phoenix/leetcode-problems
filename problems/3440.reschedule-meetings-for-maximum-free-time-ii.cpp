// @leetcode id=3440 questionId=3741 slug=reschedule-meetings-for-maximum-free-time-ii lang=cpp site=leetcode.com title="Reschedule Meetings for Maximum Free Time II"
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<long long> gap(n + 1);
        gap[0] = startTime[0];
        for (int i = 1; i < n; i++) gap[i] = startTime[i] - endTime[i - 1];
        gap[n] = eventTime - endTime[n - 1];

        // Track the top 3 (value, index) gaps so that excluding any 2
        // specific indices still leaves a valid candidate to check against.
        vector<pair<long long, int>> top;
        for (int i = 0; i <= n; i++) top.push_back({gap[i], i});
        sort(top.rbegin(), top.rend());
        while (top.size() > 3) top.pop_back();

        long long best = 0;
        for (int i = 0; i <= n; i++) best = max(best, gap[i]);

        for (int i = 0; i < n; i++) {
            long long d = endTime[i] - startTime[i];
            // Shifting the meeting to hug one edge of its own combined span
            // always works, no external gap needed.
            best = max(best, gap[i] + gap[i + 1]);

            long long maxOther = -1;
            for (auto& [v, idx] : top) {
                if (idx == i || idx == i + 1) continue;
                maxOther = max(maxOther, v);
            }
            if (maxOther >= d) {
                best = max(best, gap[i] + gap[i + 1] + d);
            }
        }
        return (int)best;
    }
};
