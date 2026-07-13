// @leetcode id=2347 questionId=2433 slug=best-poker-hand lang=cpp site=leetcode.com title="Best Poker Hand"
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool flush = all_of(suits.begin(), suits.end(), [&](char c) { return c == suits[0]; });
        if (flush) return "Flush";

        unordered_map<int, int> count;
        int best = 0;
        for (int r : ranks) best = max(best, ++count[r]);

        if (best >= 3) return "Three of a Kind";
        if (best == 2) return "Pair";
        return "High Card";
    }
};
