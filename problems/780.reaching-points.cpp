// @leetcode id=780 questionId=796 slug=reaching-points lang=cpp site=leetcode.com title="Reaching Points"
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // Work backwards from (tx, ty): the last op added the smaller
        // coordinate to the larger one repeatedly, so use mod to collapse
        // many steps at once instead of subtracting one at a time.
        long long x = tx, y = ty;
        while (x > sx && y > sy) {
            if (x > y) x %= y;
            else y %= x;
        }
        if (x == sx) return y >= sy && (y - sy) % x == 0;
        if (y == sy) return x >= sx && (x - sx) % y == 0;
        return false;
    }
};
