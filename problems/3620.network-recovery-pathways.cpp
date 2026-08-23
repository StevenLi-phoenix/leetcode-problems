// @leetcode id=3620 questionId=3919 slug=network-recovery-pathways lang=cpp site=leetcode.com title="Network Recovery Pathways"
class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        
        // Collect all unique edge costs for binary search candidates
        vector<int> costs;
        for (auto& e : edges) {
            costs.push_back(e[2]);
        }
        sort(costs.begin(), costs.end());
        costs.erase(unique(costs.begin(), costs.end()), costs.end());
        
        // Check if a path with min edge >= minCost exists with total cost <= k
        // Uses topological sort DP on the DAG
        auto check = [&](int minCost) -> bool {
            // Build graph with only edges having cost >= minCost
            // and endpoints that are online (intermediate nodes must be online)
            // node 0 and n-1 are always online
            
            // dp[v] = minimum total cost to reach v from 0
            // using only edges with cost >= minCost
            const long long INF = 2e18;
            vector<long long> dp(n, INF);
            dp[0] = 0;
            
            // Topological sort using Kahn's algorithm
            // Build adjacency list and in-degree for filtered graph
            vector<vector<pair<int,int>>> adj(n); // adj[u] = {v, cost}
            vector<int> indegree(n, 0);
            
            for (auto& e : edges) {
                int u = e[0], v = e[1], c = e[2];
                // Skip edge if intermediate nodes are offline
                // (endpoints of edge can be intermediate if they're not 0 or n-1)
                // Actually: u and v themselves must be online if they're intermediate
                // But we check online[u] and online[v] here
                // node 0 and n-1 are always online
                if (!online[u] || !online[v]) continue;
                if (c < minCost) continue;
                adj[u].push_back({v, c});
                indegree[v]++;
            }
            
            // Topological sort (Kahn's)
            queue<int> q;
            for (int i = 0; i < n; i++) {
                if (indegree[i] == 0) q.push(i);
            }
            
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto [v, c] : adj[u]) {
                    if (dp[u] != INF) {
                        dp[v] = min(dp[v], dp[u] + c);
                    }
                    indegree[v]--;
                    if (indegree[v] == 0) q.push(v);
                }
            }
            
            return dp[n-1] <= k;
        };
        
        if (!check(0)) return -1;
        
        // Binary search: find the largest minCost such that check(minCost) is true
        int lo = 0, hi = (int)costs.size() - 1, ans = -1;
        
        // First check if any valid path exists
        // check(0) means minCost=0, all edges included
        // If even with all edges no path exists with cost <= k, return -1
        // (already handled above with check(0))
        
        // But wait: check(0) uses minCost=0, filters edges >= 0 (all edges)
        // We want max minCost such that check passes
        
        // Binary search on costs array
        lo = 0; hi = (int)costs.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(costs[mid])) {
                ans = costs[mid];
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};
