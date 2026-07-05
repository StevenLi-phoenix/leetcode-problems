// @leetcode id=1284 questionId=1409 slug=minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix lang=cpp site=leetcode.com title="Minimum Number of Flips to Convert Binary Matrix to Zero Matrix"
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int start = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j]) start |= (1 << (i * n + j));
            }
        }
        if (start == 0) return 0;

        vector<int> masks(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int mask = 1 << (i * n + j);
                if (i > 0) mask |= 1 << ((i - 1) * n + j);
                if (i < m - 1) mask |= 1 << ((i + 1) * n + j);
                if (j > 0) mask |= 1 << (i * n + j - 1);
                if (j < n - 1) mask |= 1 << (i * n + j + 1);
                masks[i * n + j] = mask;
            }
        }

        vector<int> dist(1 << (m * n), -1);
        dist[start] = 0;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == 0) return dist[cur];
            for (int idx = 0; idx < m * n; ++idx) {
                int next = cur ^ masks[idx];
                if (dist[next] == -1) {
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
        }
        return -1;
    }
};
