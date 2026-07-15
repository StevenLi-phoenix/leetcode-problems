// @leetcode id=1686 questionId=1788 slug=stone-game-vi lang=cpp site=leetcode.com title="Stone Game VI"
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return aliceValues[a] + bobValues[a] > aliceValues[b] + bobValues[b];
        });

        long long aliceScore = 0, bobScore = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) aliceScore += aliceValues[idx[i]];
            else bobScore += bobValues[idx[i]];
        }

        if (aliceScore > bobScore) return 1;
        if (aliceScore < bobScore) return -1;
        return 0;
    }
};
