// @leetcode id=822 questionId=842 slug=card-flipping-game lang=cpp site=leetcode.com title="Card Flipping Game"
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> banned;
        int n = fronts.size();
        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) banned.insert(fronts[i]);
        }

        int best = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!banned.count(fronts[i])) best = min(best, fronts[i]);
            if (!banned.count(backs[i])) best = min(best, backs[i]);
        }
        return best == INT_MAX ? 0 : best;
    }
};
