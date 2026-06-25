// @leetcode id=2660 questionId=2684 slug=determine-the-winner-of-a-bowling-game lang=cpp site=leetcode.com title="Determine the Winner of a Bowling Game"
class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        auto calcScore = [](vector<int>& player) {
            int score = 0;
            int n = player.size();
            for (int i = 0; i < n; i++) {
                bool bonus = (i >= 1 && player[i-1] == 10) || (i >= 2 && player[i-2] == 10);
                score += bonus ? 2 * player[i] : player[i];
            }
            return score;
        };
        int s1 = calcScore(player1);
        int s2 = calcScore(player2);
        if (s1 > s2) return 1;
        if (s2 > s1) return 2;
        return 0;
    }
};
