// @leetcode id=1733 questionId=1834 slug=minimum-number-of-people-to-teach lang=cpp site=leetcode.com title="Minimum Number of People to Teach"
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> langSet(m + 1);
        for (int i = 0; i < m; i++) {
            langSet[i + 1] = unordered_set<int>(languages[i].begin(), languages[i].end());
        }

        unordered_set<int> problemUsers;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool common = false;
            for (int lang : langSet[u]) {
                if (langSet[v].count(lang)) { common = true; break; }
            }
            if (!common) {
                problemUsers.insert(u);
                problemUsers.insert(v);
            }
        }

        if (problemUsers.empty()) return 0;

        int best = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int needTeach = 0;
            for (int u : problemUsers) {
                if (!langSet[u].count(lang)) needTeach++;
            }
            best = min(best, needTeach);
        }
        return best;
    }
};
