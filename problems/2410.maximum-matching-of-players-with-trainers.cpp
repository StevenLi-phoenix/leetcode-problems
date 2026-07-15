// @leetcode id=2410 questionId=2497 slug=maximum-matching-of-players-with-trainers lang=cpp site=leetcode.com title="Maximum Matching of Players With Trainers"
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0, j = 0, count = 0;
        while (i < (int)players.size() && j < (int)trainers.size()) {
            if (players[i] <= trainers[j]) {
                count++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return count;
    }
};
