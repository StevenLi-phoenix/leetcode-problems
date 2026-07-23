// @leetcode id=2651 questionId=2748 slug=calculate-delayed-arrival-time lang=cpp site=leetcode.com title="Calculate Delayed Arrival Time"
class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};
