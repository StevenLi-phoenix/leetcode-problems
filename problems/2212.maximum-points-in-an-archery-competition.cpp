// @leetcode id=2212 questionId=2318 slug=maximum-points-in-an-archery-competition lang=cpp site=leetcode.com title="Maximum Points in an Archery Competition"
class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int bestScore = 0;
        int bestMask = 0;

        for (int mask = 0; mask < 4096; mask++) {
            int cost = 0, score = 0;
            for (int k = 0; k < 12; k++) {
                if (mask & (1 << k)) {
                    cost += aliceArrows[k] + 1;
                    score += k;
                }
            }
            if (cost <= numArrows && score > bestScore) {
                bestScore = score;
                bestMask = mask;
            }
        }

        vector<int> bob(12, 0);
        int used = 0;
        for (int k = 0; k < 12; k++) {
            if (bestMask & (1 << k)) {
                bob[k] = aliceArrows[k] + 1;
                used += bob[k];
            }
        }
        bob[0] += numArrows - used;
        return bob;
    }
};
