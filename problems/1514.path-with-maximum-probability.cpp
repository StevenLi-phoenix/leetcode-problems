// @leetcode id=1514 questionId=1325 slug=path-with-maximum-probability lang=cpp site=leetcode.com title="Path with Maximum Probability"
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < (int)edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back({b, succProb[i]});
            adj[b].push_back({a, succProb[i]});
        }

        vector<double> best(n, 0.0);
        best[start_node] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [prob, node] = pq.top(); pq.pop();
            if (prob < best[node]) continue;
            if (node == end_node) return prob;
            for (auto& [next, w] : adj[node]) {
                double np = prob * w;
                if (np > best[next]) {
                    best[next] = np;
                    pq.push({np, next});
                }
            }
        }
        return best[end_node];
    }
};
