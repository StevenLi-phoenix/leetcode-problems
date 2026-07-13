// @leetcode id=787 questionId=803 slug=cheapest-flights-within-k-stops lang=cpp site=leetcode.com title="Cheapest Flights Within K Stops"
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = INT_MAX;
        vector<int> dist(n, INF);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> newDist = dist;
            for (auto& f : flights) {
                int u = f[0], v = f[1], w = f[2];
                if (dist[u] != INF && dist[u] + w < newDist[v]) {
                    newDist[v] = dist[u] + w;
                }
            }
            dist = newDist;
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};
