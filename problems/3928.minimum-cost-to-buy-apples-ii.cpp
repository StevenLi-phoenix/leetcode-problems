// @leetcode id=3928 questionId=3976 slug=minimum-cost-to-buy-apples-ii lang=cpp site=leetcode.com title="Minimum Cost to Buy Apples II"
class Solution {
public:
    vector<vector<long long>> dijkstraAll(int n, vector<vector<pair<int,long long>>>& adj) {
        vector<vector<long long>> dist(n, vector<long long>(n, LLONG_MAX));
        for (int src = 0; src < n; src++) {
            dist[src][src] = 0;
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
            pq.push({0, src});
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d > dist[src][u]) continue;
                for (auto& [v, w] : adj[u]) {
                    if (dist[src][u] + w < dist[src][v]) {
                        dist[src][v] = dist[src][u] + w;
                        pq.push({dist[src][v], v});
                    }
                }
            }
        }
        return dist;
    }

    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>> adjCost(n), adjTax(n);
        for (auto& r : roads) {
            int u = r[0], v = r[1];
            long long cost = r[2], tax = r[3];
            adjCost[u].push_back({v, cost});
            adjCost[v].push_back({u, cost});
            adjTax[u].push_back({v, cost * tax});
            adjTax[v].push_back({u, cost * tax});
        }

        vector<vector<long long>> dCost = dijkstraAll(n, adjCost);
        vector<vector<long long>> dTax = dijkstraAll(n, adjTax);

        vector<int> answer(n);
        for (int i = 0; i < n; i++) {
            long long best = prices[i];
            for (int j = 0; j < n; j++) {
                if (dCost[i][j] == LLONG_MAX || dTax[i][j] == LLONG_MAX) continue;
                long long total = dCost[i][j] + dTax[i][j] + prices[j];
                best = min(best, total);
            }
            answer[i] = (int)best;
        }

        return answer;
    }
};
