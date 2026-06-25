// @leetcode id=3894 questionId=4275 slug=traffic-signal-color lang=cpp site=leetcode.com title="Traffic Signal Color"
class Solution {
public:
    string trafficSignal(int timer) {
        if (timer == 0) return "Green";
        if (timer == 30) return "Orange";
        if (timer > 30 && timer <= 90) return "Red";
        return "Invalid";
    }
};
