// @leetcode id=3015 questionId=3271 slug=count-the-number-of-houses-at-a-certain-distance-i lang=cpp site=leetcode.com title="Count the Number of Houses at a Certain Distance I"
class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adj(n + 1);
        for (int i = 1; i < n; i++) {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }
        adj[x].push_back(y);
        adj[y].push_back(x);

        vector<int> result(n + 1, 0);
        for (int src = 1; src <= n; src++) {
            vector<int> dist(n + 1, -1);
            dist[src] = 0;
            queue<int> q;
            q.push(src);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            for (int dst = 1; dst <= n; dst++) {
                if (dst != src) result[dist[dst]]++;
            }
        }

        vector<int> ans(result.begin() + 1, result.end());
        return ans;
    }
};
