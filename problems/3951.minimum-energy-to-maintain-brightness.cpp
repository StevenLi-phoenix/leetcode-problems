// @leetcode id=3951 questionId=4306 slug=minimum-energy-to-maintain-brightness lang=cpp site=leetcode.com title="Minimum Energy to Maintain Brightness"
class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        // Each lit bulb illuminates itself plus its two neighbors, so bulbs
        // spaced 3 apart cover 3 fresh positions each; the minimum bulb count
        // needed for `brightness` illuminated positions is ceil(brightness/3).
        long long bulbsNeeded = (brightness + 2) / 3;

        sort(intervals.begin(), intervals.end());
        long long totalTime = 0;
        long long curStart = -1, curEnd = -2;
        for (auto& iv : intervals) {
            if (iv[0] > curEnd + 1) {
                if (curEnd >= curStart) totalTime += curEnd - curStart + 1;
                curStart = iv[0];
                curEnd = iv[1];
            } else {
                curEnd = max(curEnd, (long long)iv[1]);
            }
        }
        if (curEnd >= curStart) totalTime += curEnd - curStart + 1;

        return bulbsNeeded * totalTime;
    }
};
