// @leetcode id=1401 questionId=1501 slug=circle-and-rectangle-overlapping lang=cpp site=leetcode.com title="Circle and Rectangle Overlapping"
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        long long closestX = clamp(xCenter, x1, x2);
        long long closestY = clamp(yCenter, y1, y2);
        long long dx = closestX - xCenter;
        long long dy = closestY - yCenter;
        return dx * dx + dy * dy <= (long long)radius * radius;
    }

private:
    long long clamp(long long v, long long lo, long long hi) {
        return max(lo, min(v, hi));
    }
};
