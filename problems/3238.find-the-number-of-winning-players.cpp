// @leetcode id=3238 questionId=3519 slug=find-the-number-of-winning-players lang=cpp site=leetcode.com title="Find the Number of Winning Players"
class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int count[10][11] = {0};
        for (auto& p : pick) {
            count[p[0]][p[1]]++;
        }

        int winners = 0;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= 10; c++) {
                if (count[i][c] >= i + 1) {
                    winners++;
                    break;
                }
            }
        }
        return winners;
    }
};
