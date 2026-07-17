// @leetcode id=2045 questionId=2171 slug=second-minimum-time-to-reach-destination lang=cpp site=leetcode.com title="Second Minimum Time to Reach Destination"
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> dist1(n + 1, -1), dist2(n + 1, -1);
        dist1[1] = 0;
        queue<pair<int,int>> q;
        q.push({1, 0});

        while (!q.empty()) {
            auto [u, d] = q.front(); q.pop();

            for (int v : adj[u]) {
                int nd = d + 1;
                if (dist1[v] == -1) {
                    dist1[v] = nd;
                    q.push({v, nd});
                } else if (dist1[v] != nd && dist2[v] == -1) {
                    dist2[v] = nd;
                    q.push({v, nd});
                }
            }
        }

        int steps = dist2[n];
        int result = 0;

        for (int i = 0; i < steps; i++) {
            if (result % (2 * change) >= change) {
                result += 2 * change - (result % (2 * change));
            }
            result += time;
        }

        return result;
    }
};
