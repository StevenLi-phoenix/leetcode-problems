// @leetcode id=3443 questionId=3754 slug=maximum-manhattan-distance-after-k-changes lang=cpp site=leetcode.com title="Maximum Manhattan Distance After K Changes"
class Solution {
public:
    int maxDistance(string s, int k) {
        int cntN = 0, cntS = 0, cntE = 0, cntW = 0;
        int best = 0;

        for (int t = 1; t <= (int)s.size(); t++) {
            char c = s[t - 1];
            if (c == 'N') cntN++;
            else if (c == 'S') cntS++;
            else if (c == 'E') cntE++;
            else cntW++;

            int base = abs(cntN - cntS) + abs(cntE - cntW);
            int cur = min(t, base + 2 * k);
            best = max(best, cur);
        }
        return best;
    }
};
