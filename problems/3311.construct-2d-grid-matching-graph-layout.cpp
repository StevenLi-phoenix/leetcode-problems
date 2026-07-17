// @leetcode id=3311 questionId=3578 slug=construct-2d-grid-matching-graph-layout lang=cpp site=leetcode.com title="Construct 2D Grid Matching Graph Layout"
class Solution {
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<unordered_set<int>> adjSet(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            adjSet[e[0]].insert(e[1]);
            adjSet[e[1]].insert(e[0]);
        }

        if (n == 1) return {{0}};

        bool has1D = false;
        int startNode = -1;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) { has1D = true; startNode = i; break; }
        }

        if (has1D) {
            vector<int> row;
            int prev = -1, cur = startNode;
            while (cur != -1) {
                row.push_back(cur);
                int nxt = -1;
                for (int nb : adj[cur]) {
                    if (nb != prev) { nxt = nb; break; }
                }
                prev = cur;
                cur = nxt;
            }
            return {row};
        }

        auto neighborExcluding = [&](int u, int ex1, int ex2) -> int {
            for (int nb : adj[u]) {
                if (nb != ex1 && nb != ex2) return nb;
            }
            return -1;
        };

        auto commonNeighbor = [&](int u, int v, int exclude) -> int {
            for (int w : adj[u]) {
                if (w != exclude && w != v && adjSet[v].count(w)) return w;
            }
            return -1;
        };

        int corner = -1, right0 = -1, down0 = -1;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 2) {
                int x = adj[i][0], y = adj[i][1];
                if (!adjSet[x].count(y)) {
                    corner = i; right0 = x; down0 = y;
                    break;
                }
            }
        }

        vector<int> row0 = {corner, right0};
        vector<int> row1 = {down0, commonNeighbor(right0, down0, corner)};

        int j = 2;
        while (true) {
            int cand = neighborExcluding(row0[j - 1], row0[j - 2], row1[j - 1]);
            if (cand == -1) break;
            row0.push_back(cand);
            int down = commonNeighbor(cand, row1[j - 1], row0[j - 1]);
            row1.push_back(down);
            j++;
        }

        int cols = row0.size();
        vector<vector<int>> grid;
        grid.push_back(row0);
        grid.push_back(row1);

        int r = 2;
        while (true) {
            int first = neighborExcluding(grid[r - 1][0], grid[r - 2][0], grid[r - 1][1]);
            if (first == -1) break;
            vector<int> row(cols);
            row[0] = first;
            for (int c = 1; c < cols; c++) {
                row[c] = commonNeighbor(grid[r - 1][c], row[c - 1], grid[r - 1][c - 1]);
            }
            grid.push_back(row);
            r++;
        }

        return grid;
    }
};
