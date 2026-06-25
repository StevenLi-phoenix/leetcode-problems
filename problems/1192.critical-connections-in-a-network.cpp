// @leetcode id=1192 questionId=1300 slug=critical-connections-in-a-network lang=cpp site=leetcode.com title="Critical Connections in a Network"
class Solution {
public:
    int timer = 0;
    
    void dfs(int u, int parent, vector<int>& disc, vector<int>& low, 
             vector<vector<int>>& adj, vector<vector<int>>& bridges) {
        disc[u] = low[u] = timer++;
        
        for (int v : adj[u]) {
            if (v == parent) continue;
            if (disc[v] == -1) {
                dfs(v, u, disc, low, adj, bridges);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    bridges.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> disc(n, -1), low(n, -1);
        vector<vector<int>> bridges;
        
        for (int i = 0; i < n; i++) {
            if (disc[i] == -1) {
                dfs(i, -1, disc, low, adj, bridges);
            }
        }
        
        return bridges;
    }
};
