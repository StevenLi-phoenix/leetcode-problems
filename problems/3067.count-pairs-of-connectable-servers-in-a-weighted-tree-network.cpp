// @leetcode id=3067 questionId=3326 slug=count-pairs-of-connectable-servers-in-a-weighted-tree-network lang=cpp site=leetcode.com title="Count Pairs of Connectable Servers in a Weighted Tree Network"
class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> result(n, 0);
        for (int c = 0; c < n; c++) {
            long long total = 0;
            long long sumSquares = 0;
            for (auto& [child, w] : adj[c]) {
                long long count = countDivisible(adj, c, child, w, signalSpeed);
                total += count;
                sumSquares += count * count;
            }
            result[c] = (int)((total * total - sumSquares) / 2);
        }
        return result;
    }

private:
    long long countDivisible(vector<vector<pair<int, int>>>& adj, int root, int start, int startDist, int speed) {
        long long count = (startDist % speed == 0) ? 1 : 0;
        vector<pair<int, long long>> stack = {{start, startDist}};
        vector<bool> visited(adj.size(), false);
        visited[root] = true;
        visited[start] = true;
        while (!stack.empty()) {
            auto [u, dist] = stack.back(); stack.pop_back();
            for (auto& [v, w] : adj[u]) {
                if (visited[v]) continue;
                visited[v] = true;
                long long nd = dist + w;
                if (nd % speed == 0) count++;
                stack.push_back({v, nd});
            }
        }
        return count;
    }
};
