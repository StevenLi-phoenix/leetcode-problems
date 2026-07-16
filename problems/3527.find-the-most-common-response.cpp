// @leetcode id=3527 questionId=3707 slug=find-the-most-common-response lang=cpp site=leetcode.com title="Find the Most Common Response"
class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> count;
        for (auto& day : responses) {
            unordered_set<string> uniqueResponses(day.begin(), day.end());
            for (auto& r : uniqueResponses) count[r]++;
        }

        string best;
        int bestCount = -1;
        for (auto& [r, c] : count) {
            if (c > bestCount || (c == bestCount && r < best)) {
                bestCount = c;
                best = r;
            }
        }
        return best;
    }
};
