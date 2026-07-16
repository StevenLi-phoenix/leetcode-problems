// @leetcode id=1042 questionId=1120 slug=flower-planting-with-no-adjacent lang=cpp site=leetcode.com title="Flower Planting With No Adjacent"
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n + 1);
        for (auto& p : paths) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        vector<int> color(n + 1, 0);
        for (int g = 1; g <= n; g++) {
            bool used[5] = {false};
            for (int nb : adj[g]) {
                if (color[nb] != 0) used[color[nb]] = true;
            }
            for (int c = 1; c <= 4; c++) {
                if (!used[c]) { color[g] = c; break; }
            }
        }
        return vector<int>(color.begin() + 1, color.end());
    }
};
