// @leetcode id=2849 questionId=3056 slug=determine-if-a-cell-is-reachable-at-a-given-time lang=cpp site=leetcode.com title="Determine if a Cell Is Reachable at a Given Time"
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        long long dx = abs((long long)sx - fx);
        long long dy = abs((long long)sy - fy);
        long long d = max(dx, dy);
        if (d == 0) return t != 1;
        return t >= d;
    }
};
