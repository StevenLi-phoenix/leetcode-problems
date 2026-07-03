// @leetcode id=2543 questionId=2635 slug=check-if-point-is-reachable lang=cpp site=leetcode.com title="Check if Point Is Reachable"
class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        long long g = gcd((long long)targetX, (long long)targetY);
        return (g & (g - 1)) == 0;
    }
};
