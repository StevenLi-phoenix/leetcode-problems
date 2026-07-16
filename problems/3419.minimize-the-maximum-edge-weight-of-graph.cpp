// @leetcode id=3419 questionId=3720 slug=minimize-the-maximum-edge-weight-of-graph lang=cpp site=leetcode.com title="Minimize the Maximum Edge Weight of Graph"
class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        // reversed adjacency: for edge A->B, in reversed graph B->A (so BFS from 0 finds nodes that can reach 0)
        vector<vector<pair<int, int>>> radj(n); // (neighbor, weight)
        vector<int> weights;
        for (auto& e : edges) {
            radj[e[1]].push_back({e[0], e[2]});
            weights.push_back(e[2]);
        }

        auto reachableCount = [&](int maxW) {
            vector<bool> visited(n, false);
            visited[0] = true;
            queue<int> bfs;
            bfs.push(0);
            int count = 1;
            while (!bfs.empty()) {
                int u = bfs.front(); bfs.pop();
                for (auto& [v, w] : radj[u]) {
                    if (w <= maxW && !visited[v]) {
                        visited[v] = true;
                        count++;
                        bfs.push(v);
                    }
                }
            }
            return count;
        };

        if (reachableCount(INT_MAX) < n) return -1;

        sort(weights.begin(), weights.end());
        weights.erase(unique(weights.begin(), weights.end()), weights.end());

        int lo = 0, hi = (int)weights.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (reachableCount(weights[mid]) == n) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return weights[lo];
    }
};
