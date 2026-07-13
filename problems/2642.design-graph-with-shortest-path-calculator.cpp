// @leetcode id=2642 questionId=2678 slug=design-graph-with-shortest-path-calculator lang=cpp site=leetcode.com title="Design Graph With Shortest Path Calculator"
class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) : n(n), adj(n) {
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});
    }

    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2) {
        vector<long long> dist(n, LLONG_MAX);
        dist[node1] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, node1});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            if (u == node2) return (int)d;
            for (auto& [v, w] : adj[u]) {
                long long nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        return dist[node2] == LLONG_MAX ? -1 : (int)dist[node2];
    }

private:
    int n;
    vector<vector<pair<int, int>>> adj;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
