// @leetcode id=1503 questionId=1627 slug=last-moment-before-all-ants-fall-out-of-a-plank lang=cpp site=leetcode.com title="Last Moment Before All Ants Fall Out of a Plank"
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int best = 0;
        for (int x : left) best = max(best, x);
        for (int x : right) best = max(best, n - x);
        return best;
    }
};
