// @leetcode id=2383 questionId=2459 slug=minimum-hours-of-training-to-win-a-competition lang=cpp site=leetcode.com title="Minimum Hours of Training to Win a Competition"
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int totalEnergy = 0;
        for (int e : energy) totalEnergy += e;
        int energyNeeded = max(0, totalEnergy - initialEnergy + 1);

        int cur = initialExperience;
        int expNeeded = 0;
        for (int e : experience) {
            if (cur <= e) {
                int diff = e - cur + 1;
                expNeeded += diff;
                cur += diff;
            }
            cur += e;
        }

        return energyNeeded + expNeeded;
    }
};
