// @leetcode id=1344 questionId=1446 slug=angle-between-hands-of-a-clock lang=cpp site=leetcode.com title="Angle Between Hands of a Clock"
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minute_angle = minutes * 6.0;
        double hour_angle = (hour % 12) * 30.0 + minutes * 0.5;
        double diff = abs(hour_angle - minute_angle);
        return min(diff, 360.0 - diff);
    }
};
