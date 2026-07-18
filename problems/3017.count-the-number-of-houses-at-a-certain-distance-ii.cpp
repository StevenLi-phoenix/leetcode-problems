// @leetcode id=3017 questionId=3310 slug=count-the-number-of-houses-at-a-certain-distance-ii lang=cpp site=leetcode.com title="Count the Number of Houses at a Certain Distance II"
class Solution {
public:
    vector<long long> delta;

    void rangeAdjust(long long lo, long long hi, int n, long long sign) {
        if (lo < 1) lo = 1;
        if (hi > n) hi = n;
        if (lo > hi) return;
        delta[lo] += sign;
        delta[hi + 1] -= sign;
    }

    vector<long long> countOfPairs(int n, int x, int y) {
        if (x > y) swap(x, y);

        delta.assign(n + 2, 0);

        // Combo A1B1: a in [1,x-1], b in [1,y], a<b. term2 = x+y+1-a-b.
        // adjust iff x+y+1-2b < 0
        for (int b = 1; b <= y; b++) {
            if (!((long long)x + y + 1 - 2LL * b < 0)) continue;
            int aHi = min(x - 1, b - 1);
            if (aHi < 1) continue;
            long long diffLo = b - aHi, diffHi = b - 1;
            long long term2Lo = (long long)x + y + 1 - aHi - b;
            long long term2Hi = (long long)x + y - b;
            rangeAdjust(diffLo, diffHi, n, -1);
            rangeAdjust(term2Lo, term2Hi, n, 1);
        }

        // Combo A2B2: a in [x,n], b in [y+1,n], a<b. term2 = a+b-x-y+1.
        // adjust iff 2a - x - y + 1 < 0
        for (int a = x; a <= n; a++) {
            if (!(2LL * a - x - y + 1 < 0)) continue;
            long long bLo = max((long long)y + 1, (long long)a + 1);
            if (bLo > n) continue;
            long long diffLo = bLo - a, diffHi = (long long)n - a;
            long long term2Lo = (long long)a + bLo - x - y + 1;
            long long term2Hi = (long long)a + n - x - y + 1;
            rangeAdjust(diffLo, diffHi, n, -1);
            rangeAdjust(term2Lo, term2Hi, n, 1);
        }

        // Combo A1B2: a in [1,x-1], b in [y+1,n]. term2 = x-y+1-a+b.
        // adjust iff x - y + 1 < 0, constant across all such pairs.
        if ((long long)x - y + 1 < 0) {
            for (int a = 1; a <= x - 1; a++) {
                long long bLo = y + 1, bHi = n;
                if (bLo > bHi) continue;
                long long diffLo = bLo - a, diffHi = bHi - a;
                long long term2Lo = (long long)x - y + 1 - a + bLo;
                long long term2Hi = (long long)x - y + 1 - a + bHi;
                rangeAdjust(diffLo, diffHi, n, -1);
                rangeAdjust(term2Lo, term2Hi, n, 1);
            }
        }

        // Combo A2B1: both a,b in [x,y], a<b (the cycle segment). term2 = C-(b-a).
        // adjust iff (b-a) > C/2
        long long C = (long long)y - x + 1;
        long long diffThresh = C / 2 + 1;
        for (long long d = diffThresh; d <= C - 1; d++) {
            long long count = C - d;
            if (count <= 0) continue;
            rangeAdjust(d, d, n, -count);
            rangeAdjust(C - d, C - d, n, count);
        }

        vector<long long> result(n + 1, 0);
        for (int k = 1; k <= n - 1; k++) result[k] = (long long)(n - k);

        long long running = 0;
        for (int k = 1; k <= n; k++) {
            running += delta[k];
            result[k] += running;
        }

        vector<long long> ans(n);
        for (int k = 1; k <= n; k++) ans[k - 1] = result[k] * 2;

        return ans;
    }
};
