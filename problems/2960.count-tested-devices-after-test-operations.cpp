// @leetcode id=2960 questionId=3220 slug=count-tested-devices-after-test-operations lang=cpp site=leetcode.com title="Count Tested Devices After Test Operations"
class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int decrement = 0, tested = 0;
        for (int b : batteryPercentages) {
            if (b - decrement > 0) {
                tested++;
                decrement++;
            }
        }
        return tested;
    }
};
