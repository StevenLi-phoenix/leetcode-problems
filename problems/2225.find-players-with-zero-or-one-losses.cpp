// @leetcode id=2225 questionId=1354 slug=find-players-with-zero-or-one-losses lang=cpp site=leetcode.com title="Find Players With Zero or One Losses"
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losses;
        for (auto& m : matches) {
            int winner = m[0], loser = m[1];
            if (!losses.count(winner)) losses[winner] = 0;
            losses[loser]++;
        }

        vector<vector<int>> result(2);
        for (auto& [player, cnt] : losses) {
            if (cnt == 0) result[0].push_back(player);
            else if (cnt == 1) result[1].push_back(player);
        }
        sort(result[0].begin(), result[0].end());
        sort(result[1].begin(), result[1].end());
        return result;
    }
};
