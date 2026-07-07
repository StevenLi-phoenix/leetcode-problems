// @leetcode id=3175 questionId=3413 slug=find-the-first-player-to-win-k-games-in-a-row lang=cpp site=leetcode.com title="Find The First Player to win K Games in a Row"
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int champion = 0;
        int wins = 0;

        for (int i = 1; i < (int)skills.size(); ++i) {
            if (skills[i] > skills[champion]) {
                champion = i;
                wins = 1;
            } else {
                ++wins;
            }
            if (wins >= k) return champion;
        }
        // queue exhausted: current champion is the global max, never loses
        return champion;
    }
};
