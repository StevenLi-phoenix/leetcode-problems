// @leetcode id=3494 questionId=3794 slug=find-the-minimum-amount-of-time-to-brew-potions lang=cpp site=leetcode.com title="Find the Minimum Amount of Time to Brew Potions"
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> prevDone(n, 0);

        for (int j = 0; j < m; j++) {
            vector<long long> arrival(n);
            long long cum = 0;
            for (int i = 0; i < n; i++) {
                arrival[i] = cum;
                cum += (long long)skill[i] * mana[j];
            }

            long long start = 0;
            for (int i = 0; i < n; i++) {
                start = max(start, prevDone[i] - arrival[i]);
            }

            vector<long long> newDone(n);
            for (int i = 0; i < n; i++) {
                newDone[i] = start + arrival[i] + (long long)skill[i] * mana[j];
            }
            prevDone = newDone;
        }

        return prevDone[n - 1];
    }
};
