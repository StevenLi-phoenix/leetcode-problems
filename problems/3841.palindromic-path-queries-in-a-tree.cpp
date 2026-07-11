// @leetcode id=3841 questionId=4209 slug=palindromic-path-queries-in-a-tree lang=cpp site=leetcode.com title="Palindromic Path Queries in a Tree"
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG = max(LOG, 1);
        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0), tin(n), tout(n);
        int timer = 0;

        // Iterative DFS (avoids stack overflow for n up to 5*10^4).
        vector<int> visited(n, 0);
        visited[0] = 1;
        vector<int> parent(n, -1);
        vector<int> childIdx(n, 0);
        vector<int> st = {0};
        parent[0] = -1;
        tin[0] = timer++;
        while (!st.empty()) {
            int u = st.back();
            if (childIdx[u] < (int)adj[u].size()) {
                int v = adj[u][childIdx[u]++];
                if (v == parent[u]) continue;
                if (visited[v]) continue;
                visited[v] = 1;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                tin[v] = timer++;
                st.push_back(v);
            } else {
                tout[u] = timer - 1;
                st.pop_back();
            }
        }

        for (int i = 0; i < n; i++) up[0][i] = (parent[i] == -1) ? i : parent[i];
        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++) up[k][i] = up[k - 1][up[k - 1][i]];

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            int diff = depth[u] - depth[v];
            for (int k = 0; k < LOG; k++)
                if (diff >> k & 1) u = up[k][u];
            if (u == v) return u;
            for (int k = LOG - 1; k >= 0; k--)
                if (up[k][u] != up[k][v]) { u = up[k][u]; v = up[k][v]; }
            return up[0][u];
        };

        // Fenwick tree supporting range XOR update + point query (prefix XOR).
        vector<int> bit(n + 2, 0);
        auto bitUpdate = [&](int i, int val) {
            for (i++; i <= n; i += i & (-i)) bit[i] ^= val;
        };
        auto bitQuery = [&](int i) {
            int res = 0;
            for (i++; i > 0; i -= i & (-i)) res ^= bit[i];
            return res;
        };
        auto rangeXor = [&](int l, int r, int val) {
            bitUpdate(l, val);
            bitUpdate(r + 1, val);
        };

        vector<int> val(n);
        for (int i = 0; i < n; i++) val[i] = 1 << (s[i] - 'a');
        for (int i = 0; i < n; i++) rangeXor(tin[i], tout[i], val[i]);

        vector<bool> ans;
        for (auto& q : queries) {
            int sp1 = q.find(' ');
            int sp2 = q.find(' ', sp1 + 1);
            string type = q.substr(0, sp1);
            if (type == "update") {
                int u = stoi(q.substr(sp1 + 1, sp2 - sp1 - 1));
                char c = q[sp2 + 1];
                int newVal = 1 << (c - 'a');
                int delta = val[u] ^ newVal;
                if (delta) rangeXor(tin[u], tout[u], delta);
                val[u] = newVal;
            } else {
                int u = stoi(q.substr(sp1 + 1, sp2 - sp1 - 1));
                int v = stoi(q.substr(sp2 + 1));
                int w = lca(u, v);
                int pathXor = bitQuery(tin[u]) ^ bitQuery(tin[v]) ^ val[w];
                ans.push_back(__builtin_popcount(pathXor) <= 1);
            }
        }
        return ans;
    }
};
