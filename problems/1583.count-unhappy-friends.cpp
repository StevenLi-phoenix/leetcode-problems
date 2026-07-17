// @leetcode id=1583 questionId=1705 slug=count-unhappy-friends lang=cpp site=leetcode.com title="Count Unhappy Friends"
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> rank(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int)preferences[i].size(); j++) {
                rank[i][preferences[i][j]] = j;
            }
        }

        vector<int> partner(n);
        for (auto& p : pairs) {
            partner[p[0]] = p[1];
            partner[p[1]] = p[0];
        }

        int count = 0;
        for (int x = 0; x < n; x++) {
            int y = partner[x];
            bool unhappy = false;
            for (int u : preferences[x]) {
                if (u == y) break;
                int v = partner[u];
                if (rank[u][x] < rank[u][v]) {
                    unhappy = true;
                    break;
                }
            }
            if (unhappy) count++;
        }
        return count;
    }
};
