// @leetcode id=1802 questionId=1929 slug=maximum-value-at-a-given-index-in-a-bounded-array lang=cpp site=leetcode.com title="Maximum Value at a Given Index in a Bounded Array"
class Solution {
public:
    long long sideSum(long long v, long long len) {
        if (len <= 0) return 0;
        if (v > len) {
            return len * v - len * (len + 1) / 2;
        } else {
            return (v - 1) * v / 2 + (len - v + 1);
        }
    }

    bool feasible(long long v, int n, int index, long long maxSum) {
        long long leftLen = index;
        long long rightLen = n - 1 - index;
        long long total = v + sideSum(v, leftLen) + sideSum(v, rightLen);
        return total <= maxSum;
    }

    int maxValue(int n, int index, int maxSum) {
        long long lo = 1, hi = maxSum;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (feasible(mid, n, index, maxSum)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return (int)lo;
    }
};
