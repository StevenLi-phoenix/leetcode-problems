// @leetcode id=495 questionId=495 slug=teemo-attacking lang=cpp site=leetcode.com title="Teemo Attacking"
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;

        for (int i = 0; i < timeSeries.size(); i++) {
            if (i == timeSeries.size() - 1) {
                total += duration;
            } else {
                int timeUntilNextAttack = timeSeries[i + 1] - timeSeries[i];
                total += min(timeUntilNextAttack, duration);
            }
        }

        return total;
    }
};
