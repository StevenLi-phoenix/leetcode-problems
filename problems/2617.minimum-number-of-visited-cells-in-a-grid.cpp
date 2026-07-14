// @leetcode id=2617 questionId=2697 slug=minimum-number-of-visited-cells-in-a-grid lang=cpp site=leetcode.com title="Minimum Number of Visited Cells in a Grid"
class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<set<int>> rowUnvisited(m), colUnvisited(n);
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) rowUnvisited[i].insert(j);
        for (int j = 0; j < n; j++) for (int i = 0; i < m; i++) colUnvisited[j].insert(i);

        vector<vector<int>> dist(m, vector<int>(n, -1));
        dist[0][0] = 1;
        rowUnvisited[0].erase(0);
        colUnvisited[0].erase(0);
        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            if (i == m - 1 && j == n - 1) return dist[i][j];
            int reach = grid[i][j];
            if (reach > 0) {
                // rightward: columns in (j, j+reach] within row i
                auto it = rowUnvisited[i].upper_bound(j);
                while (it != rowUnvisited[i].end() && *it <= j + reach) {
                    int k = *it;
                    dist[i][k] = dist[i][j] + 1;
                    colUnvisited[k].erase(i);
                    q.push({i, k});
                    it = rowUnvisited[i].erase(it);
                }
                // downward: rows in (i, i+reach] within col j
                auto it2 = colUnvisited[j].upper_bound(i);
                while (it2 != colUnvisited[j].end() && *it2 <= i + reach) {
                    int k = *it2;
                    dist[k][j] = dist[i][j] + 1;
                    rowUnvisited[k].erase(j);
                    q.push({k, j});
                    it2 = colUnvisited[j].erase(it2);
                }
            }
        }
        return -1;
    }
};
