// @leetcode id=3552 questionId=3837 slug=grid-teleportation-traversal lang=cpp site=leetcode.com title="Grid Teleportation Traversal"
class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int totalNodes = m * n + 26;
        vector<int> dist(totalNodes, INT_MAX);
        vector<vector<int>> letterCells(26);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = matrix[i][j];
                if (c >= 'A' && c <= 'Z') {
                    letterCells[c - 'A'].push_back(i * n + j);
                }
            }
        }

        deque<int> dq;
        int start = 0;
        dist[start] = 0;
        dq.push_back(start);

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!dq.empty()) {
            int u = dq.front(); dq.pop_front();
            int d = dist[u];

            if (u >= m * n) {
                // virtual letter node: 0-cost edges to all cells with that letter
                int letter = u - m * n;
                for (int cell : letterCells[letter]) {
                    if (d < dist[cell]) {
                        dist[cell] = d;
                        dq.push_front(cell);
                    }
                }
                continue;
            }

            int r = u / n, c = u % n;
            char ch = matrix[r][c];
            if (ch >= 'A' && ch <= 'Z') {
                int virt = m * n + (ch - 'A');
                if (d < dist[virt]) {
                    dist[virt] = d;
                    dq.push_front(virt);
                }
            }

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (matrix[nr][nc] == '#') continue;
                int nu = nr * n + nc;
                if (d + 1 < dist[nu]) {
                    dist[nu] = d + 1;
                    dq.push_back(nu);
                }
            }
        }

        int target = (m - 1) * n + (n - 1);
        return dist[target] == INT_MAX ? -1 : dist[target];
    }
};
