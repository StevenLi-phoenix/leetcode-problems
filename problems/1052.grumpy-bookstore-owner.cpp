// @leetcode id=1052 questionId=1138 slug=grumpy-bookstore-owner lang=cpp site=leetcode.com title="Grumpy Bookstore Owner"
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int baseSatisfied = 0;
        for (int i = 0; i < n; i++) {
            if (!grumpy[i]) baseSatisfied += customers[i];
        }

        int windowGain = 0;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i]) windowGain += customers[i];
        }
        int bestGain = windowGain;

        for (int i = minutes; i < n; i++) {
            if (grumpy[i]) windowGain += customers[i];
            if (grumpy[i - minutes]) windowGain -= customers[i - minutes];
            bestGain = max(bestGain, windowGain);
        }

        return baseSatisfied + bestGain;
    }
};
