// @leetcode id=2959 questionId=3217 slug=number-of-possible-sets-of-closing-branches lang=cpp site=leetcode.com title="Number of Possible Sets of Closing Branches"
class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        // n <= 10, so brute-force every subset of branches to KEEP active,
        // run Floyd-Warshall restricted to that subset, and check all
        // pairwise distances are within budget.
        const long long INF = LLONG_MAX / 4;
        int count = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            vector<vector<long long>> dist(n, vector<long long>(n, INF));
            for (int i = 0; i < n; i++)
                if (mask & (1 << i)) dist[i][i] = 0;

            for (auto& r : roads) {
                int u = r[0], v = r[1], w = r[2];
                if (!(mask & (1 << u)) || !(mask & (1 << v))) continue;
                dist[u][v] = min(dist[u][v], (long long)w);
                dist[v][u] = min(dist[v][u], (long long)w);
            }

            for (int k = 0; k < n; k++) {
                if (!(mask & (1 << k))) continue;
                for (int i = 0; i < n; i++) {
                    if (!(mask & (1 << i))) continue;
                    for (int j = 0; j < n; j++) {
                        if (!(mask & (1 << j))) continue;
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }

            bool ok = true;
            for (int i = 0; i < n && ok; i++) {
                if (!(mask & (1 << i))) continue;
                for (int j = 0; j < n && ok; j++) {
                    if (!(mask & (1 << j))) continue;
                    if (dist[i][j] > maxDistance) ok = false;
                }
            }
            if (ok) count++;
        }
        return count;
    }
};
