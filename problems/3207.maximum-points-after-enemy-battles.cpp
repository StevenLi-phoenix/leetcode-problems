// @leetcode id=3207 questionId=3264 slug=maximum-points-after-enemy-battles lang=cpp site=leetcode.com title="Maximum Points After Enemy Battles"
class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long minVal = *min_element(enemyEnergies.begin(), enemyEnergies.end());
        if (currentEnergy < minVal) return 0;

        long long sum = 0;
        for (int e : enemyEnergies) sum += e;

        long long totalPool = currentEnergy + (sum - minVal);
        return totalPool / minVal;
    }
};
