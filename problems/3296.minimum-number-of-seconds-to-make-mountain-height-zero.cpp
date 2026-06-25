// @leetcode id=3296 questionId=3496 slug=minimum-number-of-seconds-to-make-mountain-height-zero lang=cpp site=leetcode.com title="Minimum Number of Seconds to Make Mountain Height Zero"
class Solution {
    public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    long long lo = 1, hi = 1e18;
    while (lo < hi) {
    long long mid = lo + (hi - lo) / 2;
    long long total = 0;
    for (int w : workerTimes) {
    long long x = (long long)((-1.0 + sqrt(1.0 + 8.0 * mid / w)) / 2.0);
    while ((long long)w * (x + 1) * (x + 2) / 2 <= mid) x++;
    total += x;
    if (total >= mountainHeight) break;
    }
    if (total >= mountainHeight) hi = mid;
    else lo = mid + 1;
    }
    return lo;
    }
    };
