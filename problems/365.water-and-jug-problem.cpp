// @leetcode id=365 questionId=365 slug=water-and-jug-problem lang=cpp site=leetcode.com title="Water and Jug Problem"
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return false;
        if (x == 0 || y == 0) return target == 0 || target == x + y;
        int g = std::__gcd(x, y);
        return target % g == 0;
    }
};
