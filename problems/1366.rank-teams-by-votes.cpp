// @leetcode id=1366 questionId=1483 slug=rank-teams-by-votes lang=cpp site=leetcode.com title="Rank Teams by Votes"
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if (votes.empty()) return "";
        int numPositions = votes[0].size();
        unordered_map<char, vector<int>> count;
        for (char c : votes[0]) count[c] = vector<int>(numPositions, 0);

        for (auto& vote : votes) {
            for (int i = 0; i < (int)vote.size(); i++) count[vote[i]][i]++;
        }

        vector<char> teams;
        for (auto& [c, v] : count) teams.push_back(c);

        sort(teams.begin(), teams.end(), [&](char a, char b) {
            if (count[a] != count[b]) return count[a] > count[b];
            return a < b;
        });

        return string(teams.begin(), teams.end());
    }
};
