// @leetcode id=1326 questionId=1451 slug=minimum-number-of-taps-to-open-to-water-a-garden lang=cpp site=leetcode.com title="Minimum Number of Taps to Open to Water a Garden"
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> farthest(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            int lo = max(0, i - ranges[i]);
            int hi = min(n, i + ranges[i]);
            farthest[lo] = max(farthest[lo], hi);
        }

        int taps = 0, curEnd = 0, nextEnd = 0;
        int i = 0;
        while (curEnd < n) {
            while (i <= curEnd) {
                nextEnd = max(nextEnd, farthest[i]);
                i++;
            }
            if (nextEnd <= curEnd) return -1;
            taps++;
            curEnd = nextEnd;
        }
        return taps;
    }
};
