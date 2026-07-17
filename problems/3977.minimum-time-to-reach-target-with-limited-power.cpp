// @leetcode id=3977 questionId=4206 slug=minimum-time-to-reach-target-with-limited-power lang=cpp site=leetcode.com title="Minimum Time to Reach Target With Limited Power"
class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int,long long>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], (long long)e[2]});
        }

        const long long INF = LLONG_MAX;
        vector<vector<long long>> dist(n, vector<long long>(power + 1, INF));
        dist[source][power] = 0;

        priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<>> pq;
        pq.push({0, source, power});

        while (!pq.empty()) {
            auto [time, node, p] = pq.top();
            pq.pop();
            if (time > dist[node][p]) continue;

            if (p < cost[node]) continue;
            int newP = p - cost[node];

            for (auto& [v, w] : adj[node]) {
                long long newTime = time + w;
                if (newTime < dist[v][newP]) {
                    dist[v][newP] = newTime;
                    pq.push({newTime, v, newP});
                }
            }
        }

        long long bestTime = INF;
        for (int p = 0; p <= power; p++) {
            bestTime = min(bestTime, dist[target][p]);
        }

        if (bestTime == INF) return {-1, -1};

        long long bestPower = -1;
        for (int p = power; p >= 0; p--) {
            if (dist[target][p] == bestTime) {
                bestPower = p;
                break;
            }
        }

        return {bestTime, bestPower};
    }
};
