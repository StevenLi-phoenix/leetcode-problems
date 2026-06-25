// @leetcode id=3600 questionId=3902 slug=maximize-spanning-tree-stability-with-upgrades lang=cpp site=leetcode.com title="Maximize Spanning Tree Stability with Upgrades"
class Solution {
    public:
    vector<int> par, rnk;
    int find(int x) { while (par[x] != x) par[x] = par[par[x]], x = par[x]; return x; }
    bool unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return false;
    if (rnk[a] < rnk[b]) swap(a, b);
    par[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
    return true;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
    // First check if must edges form a cycle
    par.resize(n); rnk.assign(n, 0);
    iota(par.begin(), par.end(), 0);
    for (auto& e : edges) {
    if (e[3] == 1) {
    if (!unite(e[0], e[1])) return -1;
    }
    }
    // Check if graph can be connected at all (using all edges)
    for (auto& e : edges) {
    if (e[3] == 0) unite(e[0], e[1]);
    }
    int comp = 0;
    for (int i = 0; i < n; i++) if (find(i) == i) comp++;
    if (comp > 1) return -1;
    // Binary search on the answer
    int lo = 1, hi = 200001, ans = -1;
    while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    par.assign(n, 0); rnk.assign(n, 0);
    iota(par.begin(), par.end(), 0);
    bool ok = true;
    for (auto& e : edges) {
    if (e[3] == 1) {
    unite(e[0], e[1]);
    if (e[2] < mid) ok = false;
    }
    }
    if (!ok) { hi = mid - 1; continue; }
    // Add free optional edges (strength >= mid)
    for (auto& e : edges) {
    if (e[3] == 0 && e[2] >= mid) unite(e[0], e[1]);
    }
    // Add upgrade optional edges (2*strength >= mid), count upgrades used
    int used = 0;
    for (auto& e : edges) {
    if (e[3] == 0 && e[2] < mid && 2 * e[2] >= mid) {
    if (find(e[0]) != find(e[1])) { unite(e[0], e[1]); used++; }
    }
    }
    int c = 0;
    for (int i = 0; i < n; i++) if (find(i) == i) c++;
    if (c == 1 && used <= k) { ans = mid; lo = mid + 1; }
    else { hi = mid - 1; }
    }
    return ans;
    }
    };
