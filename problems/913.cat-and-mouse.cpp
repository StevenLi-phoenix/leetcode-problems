// @leetcode id=913 questionId=949 slug=cat-and-mouse lang=cpp site=leetcode.com title="Cat and Mouse"
class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        const int DRAW = 0, MOUSE = 1, CAT = 2;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, DRAW)));
        vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(2, 0)));

        for (int m = 0; m < n; m++) {
            for (int c = 0; c < n; c++) {
                degree[m][c][0] = graph[m].size();
                degree[m][c][1] = 0;
                for (int node : graph[c]) {
                    if (node != 0) degree[m][c][1]++;
                }
            }
        }

        queue<tuple<int, int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int t = 0; t < 2; t++) {
                dp[0][i][t] = MOUSE;
                q.push({0, i, t});
                if (i > 0) {
                    dp[i][i][t] = CAT;
                    q.push({i, i, t});
                }
            }
        }

        while (!q.empty()) {
            auto [m, c, t] = q.front();
            q.pop();
            int res = dp[m][c][t];

            if (t == 0) {
                for (int prev_c : graph[c]) {
                    if (prev_c == 0) continue;
                    if (dp[m][prev_c][1] != DRAW) continue;
                    if (res == CAT) {
                        dp[m][prev_c][1] = CAT;
                        q.push({m, prev_c, 1});
                    } else {
                        degree[m][prev_c][1]--;
                        if (degree[m][prev_c][1] == 0) {
                            dp[m][prev_c][1] = MOUSE;
                            q.push({m, prev_c, 1});
                        }
                    }
                }
            } else {
                for (int prev_m : graph[m]) {
                    if (dp[prev_m][c][0] != DRAW) continue;
                    if (res == MOUSE) {
                        dp[prev_m][c][0] = MOUSE;
                        q.push({prev_m, c, 0});
                    } else {
                        degree[prev_m][c][0]--;
                        if (degree[prev_m][c][0] == 0) {
                            dp[prev_m][c][0] = CAT;
                            q.push({prev_m, c, 0});
                        }
                    }
                }
            }
        }

        return dp[1][2][0];
    }
};
