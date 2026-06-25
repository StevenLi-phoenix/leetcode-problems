// @leetcode id=2260 questionId=2338 slug=minimum-consecutive-cards-to-pick-up lang=cpp site=leetcode.com title="Minimum Consecutive Cards to Pick Up"
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> lastPos;
        int minLen = INT_MAX;

        for (int i = 0; i < cards.size(); i++) {
            if (lastPos.count(cards[i])) {
                minLen = min(minLen, i - lastPos[cards[i]] + 1);
            }
            lastPos[cards[i]] = i;
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};
