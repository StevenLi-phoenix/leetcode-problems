// @leetcode id=1817 questionId=1945 slug=finding-the-users-active-minutes lang=cpp site=leetcode.com title="Finding the Users Active Minutes"
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> userTimes;
        for (auto& log : logs) {
            userTimes[log[0]].insert(log[1]);
        }

        vector<int> answer(k + 1, 0);
        for (auto& [id, times] : userTimes) {
            int uam = times.size();
            if (uam >= 1 && uam <= k) answer[uam]++;
        }
        return vector<int>(answer.begin() + 1, answer.end());
    }
};
