// @leetcode id=3515 questionId=3829 slug=shortest-path-in-a-weighted-tree lang=cpp site=leetcode.com title="Shortest Path in a Weighted Tree"
#include <bits/stdc++.h>
using namespace std;

// BIT supporting range-add / point-query via difference array trick
struct BIT {
    int n;
    vector<long long> t;
    BIT(int n) : n(n), t(n + 2, 0) {}
    void add(int i, long long v) { for (; i <= n; i += i & -i) t[i] += v; }
    void range_add(int l, int r, long long v) { add(l, v); add(r + 1, -v); }
    long long query(int i) { long long s = 0; for (; i > 0; i -= i & -i) s += t[i]; return s; }
};

class Solution {
public:
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> dist(n + 1, 0);
        vector<int> in(n + 1), out(n + 1);
        // For each edge key (min,max) → child node and current weight
        map<pair<int,int>, int> edge_child;
        map<pair<int,int>, int> cur_w;
        for (auto& e : edges)
            cur_w[{min(e[0], e[1]), max(e[0], e[1])}] = e[2];

        // Iterative DFS for Euler tour
        int timer = 0;
        stack<tuple<int,int,int>> stk;  // (node, parent, adj-index)
        stk.push({1, 0, 0});
        in[1] = ++timer;

        while (!stk.empty()) {
            auto& [v, p, idx] = stk.top();
            if (idx < (int)adj[v].size()) {
                auto [u, w] = adj[v][idx++];
                if (u != p) {
                    dist[u] = dist[v] + w;
                    in[u] = ++timer;
                    edge_child[{min(u, v), max(u, v)}] = u;
                    stk.push({u, v, 0});
                }
            } else {
                out[v] = timer;
                stk.pop();
            }
        }

        BIT bit(n);
        vector<int> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                auto key = make_pair(min(q[1], q[2]), max(q[1], q[2]));
                int child = edge_child[key];
                long long delta = q[3] - cur_w[key];
                cur_w[key] = q[3];
                bit.range_add(in[child], out[child], delta);
            } else {
                int x = q[1];
                ans.push_back((int)(dist[x] + bit.query(in[x])));
            }
        }
        return ans;
    }
};
