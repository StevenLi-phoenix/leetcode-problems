// @leetcode id=1510 questionId=1617 slug=stone-game-iv lang=cpp site=leetcode.com title="Stone Game IV"
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> win(n + 1, false);
        for (int i = 1; i <= n; i++) {
            for (int s = 1; s * s <= i; s++) {
                if (!win[i - s * s]) {
                    win[i] = true;
                    break;
                }
            }
        }
        return win[n];
    }
};
