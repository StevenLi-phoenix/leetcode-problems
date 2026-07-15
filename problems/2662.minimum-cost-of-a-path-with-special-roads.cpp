// @leetcode id=2662 questionId=2686 slug=minimum-cost-of-a-path-with-special-roads lang=cpp site=leetcode.com title="Minimum Cost of a Path With Special Roads"
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        auto manhattan = [](long long x1, long long y1, long long x2, long long y2) {
            return llabs(x2 - x1) + llabs(y2 - y1);
        };

        vector<pair<long long, long long>> nodes;
        nodes.push_back({start[0], start[1]});
        for (auto& r : specialRoads) {
            nodes.push_back({r[0], r[1]});
            nodes.push_back({r[2], r[3]});
        }
        nodes.push_back({target[0], target[1]});

        int n = nodes.size();
        int startIdx = 0, targetIdx = n - 1;

        vector<long long> dist(n, LLONG_MAX);
        dist[startIdx] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, startIdx});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            if (u == targetIdx) break;

            for (int v = 0; v < n; v++) {
                if (v == u) continue;
                long long w = manhattan(nodes[u].first, nodes[u].second, nodes[v].first, nodes[v].second);
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }

            for (size_t i = 0; i < specialRoads.size(); i++) {
                auto& r = specialRoads[i];
                if (nodes[u].first == r[0] && nodes[u].second == r[1]) {
                    int v = 1 + 2 * (int)i + 1; // index of (x2,y2) for road i
                    long long w = r[4];
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
        }

        return (int)dist[targetIdx];
    }
};
