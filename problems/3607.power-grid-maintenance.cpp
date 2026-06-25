// @leetcode id=3607 questionId=3863 slug=power-grid-maintenance lang=cpp site=leetcode.com title="Power Grid Maintenance"
class Solution {
    public:
    vector<int> par, rnk;
    int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
    void unite(int a, int b, vector<set<int>>& st) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (rnk[a] < rnk[b]) swap(a, b);
    par[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
    if (st[a].size() < st[b].size()) swap(st[a], st[b]);
    for (int v : st[b]) st[a].insert(v);
    st[b].clear();
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
    par.resize(c + 1);
    rnk.resize(c + 1, 0);
    for (int i = 0; i <= c; i++) par[i] = i;
    vector<set<int>> st(c + 1);
    vector<bool> online(c + 1, true);
    for (int i = 1; i <= c; i++) st[i].insert(i);
    for (auto& e : connections) unite(e[0], e[1], st);
    vector<int> ans;
    for (auto& q : queries) {
    if (q[0] == 1) {
    int x = q[1];
    if (online[x]) {
    ans.push_back(x);
    } else {
    int root = find(x);
    if (st[root].empty()) ans.push_back(-1);
    else ans.push_back(*st[root].begin());
    }
    } else {
    int x = q[1];
    online[x] = false;
    int root = find(x);
    st[root].erase(x);
    }
    }
    return ans;
    }
    };
