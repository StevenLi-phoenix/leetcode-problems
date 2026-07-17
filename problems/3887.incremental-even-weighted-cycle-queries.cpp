// @leetcode id=3887 questionId=4114 slug=incremental-even-weighted-cycle-queries lang=cpp site=leetcode.com title="Incremental Even-Weighted Cycle Queries"
class Solution {
public:
    vector<int> parent;
    vector<int> parity;

    pair<int,int> find(int x) {
        vector<int> chain;
        int cur = x;
        while (parent[cur] != cur) {
            chain.push_back(cur);
            cur = parent[cur];
        }
        int root = cur;

        int suffix = 0;
        for (int i = chain.size() - 1; i >= 0; i--) {
            int node = chain[i];
            suffix ^= parity[node];
            parent[node] = root;
            parity[node] = suffix;
        }

        return {root, chain.empty() ? 0 : parity[x]};
    }

    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        parity.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);

        int count = 0;

        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            auto [ru, pu] = find(u);
            auto [rv, pv] = find(v);

            if (ru == rv) {
                if (((pu ^ pv ^ w) & 1) == 0) count++;
            } else {
                parent[ru] = rv;
                parity[ru] = pu ^ pv ^ w;
                count++;
            }
        }

        return count;
    }
};
